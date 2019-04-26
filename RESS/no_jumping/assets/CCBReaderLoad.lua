ccb = ccb or {}


local ccbDebug = true

local CCBLog = function(...)
    print(string.format(...))
end

function CCBuilderReaderLoad(strFilePath,proxy,owner)
    if nil == proxy then
        return
    end

    local ccbReader = proxy:createCCBReader()
    local node      = ccbReader:load(strFilePath)
    local rootName  = ""

    if nil ~= owner then
        --Callbacks
        local ownerCallbackNames = tolua.cast(ccbReader:getOwnerCallbackNames(),"CCArray")
        local ownerCallbackNodes = tolua.cast(ccbReader:getOwnerCallbackNodes(),"CCArray")
        local ownerCallbackControlEvents = tolua.cast(ccbReader:getOwnerCallbackControlEvents(),"CCArray")
        local i = 1
        for i = 1,ownerCallbackNames:count() do
            local callbackName =  tolua.cast(ownerCallbackNames:objectAtIndex(i - 1),"CCString"):getCString()
            local callbackNode =  tolua.cast(ownerCallbackNodes:objectAtIndex(i - 1),"CCNode")

            if "function" == type(owner[callbackName]) then
                local integerValue = tolua.cast(ownerCallbackControlEvents:objectAtIndex(i - 1),"CCInteger")
                if nil ~= integerValue then
                    proxy:setCallback(callbackNode, function(...)
                            owner[callbackName](owner,...)
                        end, integerValue:getValue())
                end
            else
                CCBLog("Warning: Cannot find owner's lua function:" .. ":" .. callbackName .. " for ownerVar selector")
            end

        end
        --Variables
        local ownerOutletNames =  tolua.cast(ccbReader:getOwnerOutletNames(),"CCArray")
        local ownerOutletNodes =  tolua.cast(ccbReader:getOwnerOutletNodes(),"CCArray") 
        for i = 1, ownerOutletNames:count() do
            local outletName = tolua.cast(ownerOutletNames:objectAtIndex(i - 1),"CCString")            
            local _,_,outName,classname = string.find(outletName:getCString(), '(.*)@(.*)')
            classname = classname or "CCNode"
            local outletNode = tolua.cast(ownerOutletNodes:objectAtIndex(i - 1),classname)
            owner[outName] = outletNode
        end
    end

    local nodesWithAnimationManagers = tolua.cast(ccbReader:getNodesWithAnimationManagers(),"CCArray")
    local animationManagersForNodes  = tolua.cast(ccbReader:getAnimationManagersForNodes(),"CCArray")

    if nodesWithAnimationManagers then
        for i = 1 , nodesWithAnimationManagers:count() do
            local innerNode = tolua.cast(nodesWithAnimationManagers:objectAtIndex(i - 1),"CCNode")
            local animationManager = tolua.cast(animationManagersForNodes:objectAtIndex(i - 1), "CCBAnimationManager")
            local documentControllerName = animationManager:getDocumentControllerName()
            local currOwner = {}
            if "" == documentControllerName then
                currOwner = owner
            elseif nil ~= owner[documentControllerName] then
                currOwner = owner[documentControllerName]
            else
                if nil ~= ccb[documentControllerName] then
                    setmetatable(owner[documentControllerName], ccb[documentControllerName])
                    ccb[documentControllerName].__index = ccb[documentControllerName]
                end
                owner[documentControllerName] = currOwner
            end

            if nil ~=  currOwner then
                currOwner["mAnimationManager"] = animationManager
            end
            
            --Callbacks
            local documentCallbackNames = tolua.cast(animationManager:getDocumentCallbackNames(),"CCArray")
            local documentCallbackNodes = tolua.cast(animationManager:getDocumentCallbackNodes(),"CCArray")
            local documentCallbackControlEvents = tolua.cast(animationManager:getDocumentCallbackControlEvents(),"CCArray")

            for i = 1,documentCallbackNames:count() do
                local callbackName = tolua.cast(documentCallbackNames:objectAtIndex(i - 1),"CCString")
                local callbackNode = tolua.cast(documentCallbackNodes:objectAtIndex(i - 1),"CCNode")
                if "" ~= documentControllerName and nil ~= currOwner then
                    local cbName = callbackName:getCString()
                    if "function" == type(currOwner[cbName]) then
                        local integerValue = tolua.cast(documentCallbackControlEvents:objectAtIndex(i - 1),"CCInteger")
                        if nil ~= integerValue then
                            proxy:setCallback(callbackNode, function(...)
                                    currOwner[cbName](currOwner, ...)
                                end, integerValue:getValue())
                        end
                    else
                        CCBLog("Warning: Cannot found lua function [" .. documentControllerName .. ":" .. cbName .. "] for docRoot selector")
                    end
                end
            end

            --Variables
            local documentOutletNames =  tolua.cast(animationManager:getDocumentOutletNames(),"CCArray")
            local documentOutletNodes = tolua.cast(animationManager:getDocumentOutletNodes(),"CCArray")

            for i = 1, documentOutletNames:count() do
                local outletName = tolua.cast(documentOutletNames:objectAtIndex(i - 1),"CCString")
                local outletNode = tolua.cast(documentOutletNodes:objectAtIndex(i - 1),"CCNode")
                if nil ~= currOwner then
                    local _,_,outName,classname = string.find(outletName:getCString(), '(.*)@(.*)')
                    if classname==nil then
                        currOwner[outName] = tolua.cast(outletNode, proxy:getNodeTypeName(outletNode))
                    else
                        currOwner[outName] = tolua.cast(outletNode, classname)
                    end
                end
            end

            --Setup timeline callbacks
            local keyframeCallbacks = animationManager:getKeyframeCallbacks()

            for i = 1 , keyframeCallbacks:count() do
                local callbackCombine = tolua.cast(keyframeCallbacks:objectAtIndex(i - 1),"CCString"):getCString()
                local beignIndex,endIndex = string.find(callbackCombine,":")
                local callbackType    = tonumber(string.sub(callbackCombine,1,beignIndex - 1))
                local callbackName    = string.sub(callbackCombine,endIndex + 1, -1)
                --Document callback

                if 1 == callbackType and nil ~= currOwner then
                    if nil ~= currOwner[callbackName] then
                        local callfunc = CCCallFunc:create(function()
                                currOwner[callbackName](currOwner)
                            end)
                        animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                    else
                        local callfunc = CCCallFunc:create(nocallFunction)
                        animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                        CCBLog("No ccb Callback function:"..callbackName)
                    end
                    
                elseif 2 == callbackType and nil ~= owner then --Owner callback
                    if nil ~= owner[callbackName] then
                        local callfunc = CCCallFunc:create(function()
                                owner[callbackName](owner)
                            end)
                        animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                    else
                        local callfunc = CCCallFunc:create(nocallFunction)
                        animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                        CCBLog("No ccb owner Callback function:"..callbackName)
                    end
                end
            end
            --start animation
            local autoPlaySeqId = animationManager:getAutoPlaySequenceId()
            if -1 ~= autoPlaySeqId then
                animationManager:runAnimationsForSequenceIdTweenDuration(autoPlaySeqId, 0)
            end
        end

    end

    return node
end

--处理空回调
function nocallFunction(  )
    -- body
    CCBLog("没有实现回调函数，调用空函数")
end

function CCBReaderLoad(strFilePath,proxy,bSetOwner,strOwnerName)
    print("CCBReaderLoad was deprecated, Please use CCBuilderReaderLoad(strFilePath,proxy,owner) instead.In the newest CocosBuilderTest,you can find out the usage of this new function")
    return
end
