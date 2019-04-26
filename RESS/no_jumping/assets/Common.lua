-- avoid memory leak
collectgarbage("setpause", 100)
--collectgarbage("setpause", 0.3)
collectgarbage("setstepmul", 5000)
-- collectgarbage("setstepmul", 100)

DEBUG_MODE = true

local OPEN_CTDUMP = true  			    --CT测试dump
local OPEN_CTTrace = true  			--CT测试trace
local OPEN_CCLOG = true			-- 测试普通日志
local OPEN_CCNETLOG = true			-- 测试网络日志

--初始化随机值
math.randomseed(os.time())
math.random(1241232)	-- 第一次的随机值是不靠谱的，所以初始化先随机一次


CCLOG = function(...)
	if OPEN_CCLOG then
		-- test_print(...)
        if(select("#",...) > 1) then
	        print("LUA--"..string.format(...))
        else
            print("LUA--"..select(1,...))
        end
	end
end
printError = CCLOG

CCNETLOG = function(...)
	if OPEN_CCNETLOG then
		-- test_print(...)
        if(select("#",...) > 1) then
            print("NETLUA--"..string.format(...))
        else
            print("NETLUA--"..select(1,...))
        end
	end
end


--打印某对象的值
GF_dump = function(object, label, nesting, nest)
    if not (DEBUG_MODE and OPEN_CTDUMP) then    return  end
    if type(nesting) ~= "number" then nesting = 99 end
    local lookup_table = {}
    local function _dump(object, label, indent, nest)
        label = label or "<var>"
        if type(object) ~= "table" then
            print(string.format("%s%s = %s", indent, tostring(label), tostring(object)..""))
        elseif lookup_table[object] then
            print(string.format("%s%s = *REF*", indent, tostring(label)))
        else
            lookup_table[object] = true
            if nest > nesting then
                print(string.format("%s%s = *MAX NESTING*", indent, label))
            else
                print(string.format("%s%s = {", indent, tostring(label)))
                local indent2 = indent.."    "
                for k, v in pairs(object) do
                    _dump(v, k, indent2, nest + 1)
                end
                print(string.format("%s}", indent))
            end
        end
    end
    _dump(object, label, "- ", 1)
end

GF_trace = function(msg)
	if DEBUG_MODE and OPEN_CTTrace then
		print("----------------------------------------")
		if msg then
			print("traceback for msg : "..msg)
		end
		print(debug.traceback())
		print("----------------------------------------")
    end
end

G_nodeRecord = {}
GF_nodeCreate = function(key)
    G_nodeRecord[key] = debug.traceback()
end

GF_nodeRemove = function(key)
    if G_nodeRecord[key] then
        G_nodeRecord[key] = nil
    end
end

GF_dumpNodeRec = function()
    for k, v in pairs(G_nodeRecord) do
        print(string.format('obj: %s \n%s\n',k,v))
    end
end

GF_clearNodeRec = function()
    G_nodeRecord = {}
end

--临时持有全局变量------------------------------------------------------------------------
--[[
   临时变量有可能会被垃圾回收掉，可以用这个表缓存一下
]]--
FV_TEMP_RETAIN = {}
function GF_retainObject(key, obj)
	FV_TEMP_RETAIN[key] = obj
end

function GF_releaseObject(key, obj)
	FV_TEMP_RETAIN[key] = nil
end

-- 挎贝文件
function GF_copyFile( fromPath, toPath )
	local fromFile = io.open(fromPath, "r")
    local toFile = io.open(toPath, "w")
    local wholeFile = fromFile:read("*all")
	toFile:write(wholeFile)
	io.close(fromFile)
	io.close(toFile)
end


--输出table变量至io
local function serializeToString (key, o, tab)
    local short = tab..(key and key..'=' or '')
	if type(o) == "number" then
    	return  short..string.format('%s', tostring(o))
   	elseif type(o) == "string" then
       	return short..string.format('%q', o)
  	elseif type(o) == "table" then
        local content = ''
        local hasChild = false
       	for k,v in pairs(o) do
            hasChild = true
       		if type(k) ~= "number" then
          		content = string.format('%s%s,\n', content, serializeForString(tostring(k), v, tab..'\t'))
          	else
          		content = string.format('%s%s,\n', content, serializeForString(nil, v, tab..'\t'))
          	end
        end
        return short..(hasChild and '{\n' or '{')..content..(hasChild and tab or '')..'}'
	elseif type(o) == "boolean" then
		if o then 
     	  	return short..'true'
        else
            return short..'false'
        end
    elseif type(o) == "function" then
        return short..'function end'
    else
        return '--'..short..tostring(o)
   	end
end

-- 紧凑dump变量，用于保存文件
local function serializeToStringExplicit (tableName, o)
	local fileString = ""
	if tableName then
		fileString = tableName.."="
	end

	if type(o) == "number" then
    	fileString =  string.format('%s%s\n', fileString, tostring(o))
   	elseif type(o) == "string" then
       	fileString = string.format("%s%q\n", fileString, o)
  	elseif type(o) == "table" then
       	fileString = string.format("%s{}\n", fileString)
       	for k,v in pairs(o) do
            if type(k) ~= "number" then
                fileString = string.format("%s %s", fileString, serializeToStringExplicit(string.format("%s['%s']",tableName,k), v))
            else
                fileString = string.format("%s %s", fileString, serializeToStringExplicit(string.format("%s[%s]",tableName,k), v))
            end
		end
	elseif type(o) == "boolean" then
		if o then
     	  	fileString = string.format("%s true\n", fileString)
		else
     	  	fileString = string.format("%s false\n", fileString)
        end
    else
        return ''
--        fileString = string.format("%s function()\n\tCCLOG('!!Error: function lost when serialized!!')\n end\n", fileString)
--   		GF_trace("error_when_serialize")
--       	error("cannot serialize a " .. type(o))
   	end
   	return fileString
end

function GF_saveTableToFile(table, tableName, filePath)
    local tableString = serializeToStringExplicit(tableName, table)
    io.writefile(filePath, tableString)
end

--[[------------------------------------------------------------------
	保存文件
	table		要保存的表
	tableName	保存文件中bable变量的名称，若不指定，则读出的文件无法解析
	fileName	要保存至的文件
--]]------------------------------------------------------------------
function GF_saveTableToFileEncrypt(table, tableName, fileName)
    local tableString = serializeToStringExplicit(tableName, table)
    RedUtils:encryptStr2File(tableString, fileName..'d')
end



scheduler = CCDirector:sharedDirector():getScheduler()

function scheduleOnce(fun, delay, owner)
    local handle
    handle = scheduler:scheduleScriptFunc(function()
            scheduler:unscheduleScriptEntry(handle)
            if owner then
                fun(owner)
            else
                fun()
            end
        end, delay, false)
    return handle
end


------------------------------ string utils --------------------------
function utfsub(str, start, len)
  local fixLen = #"工"
  local function nextPos(str, pos)
    if string.byte(str, pos) > 127 then
      return pos + fixLen
    else
      return pos + 1
    end
  end
  local pos = 1
  for i = 1, start - 1 do
    pos = nextPos(str, pos)
  end

  local pos2 = pos
  for i = 1, len do
    pos2 = nextPos(str, pos2)
    if pos2 >= #str then 
      pos2 = #str+1
      break
    end
  end
  return string.sub(str, pos, pos2 - 1)
end

function utfCount(str)
    local fixLen = #"工"
    local function nextPos(str, pos)
        if string.byte(str, pos) > 127 then
            return pos + 2
        else
            return pos + 1
        end
    end
    local pos = 1
    local len = #str
    local count = 1
    while pos < len do
        pos = nextPos(str, pos)
        count = count + 1
    end
    return count
end

function utfCut(str, len)
    local fixLen = #"工"
    local function nextPos(str, pos)
        if string.byte(str, pos) > 127 then
            return pos + fixLen, 2
        else
            return pos + 1, 1
        end
    end
    local pos = 1
    local i = 1
    local charLen = 1
    while(i <= len*2) do
        pos, charLen = nextPos(str, pos)
        i = i + charLen
        if pos >= #str then
            pos = #str+1
            break
        end
    end
    return string.sub(str, 1, pos-1)
end

-- 如果字符串大于len(汉字)，则截断加上省略号
function cutStrto(str, len)
    CCLOG("source:\t"..str)
  if utfCount(str) < len*2 then return str end
  local res = utfCut(str, len-1)
  if utfCount(res) < #str-2 then
    res = res .. '...'
  end
    CCLOG("result:\t"..res)
  return res
end 
