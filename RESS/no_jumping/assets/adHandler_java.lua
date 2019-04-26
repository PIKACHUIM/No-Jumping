--
-- User: Kevin Chang
-- Date: 14-6-28
-- Time: 上午10:32
-- 
--

ADHandler = {}


function    ADHandler:isPopupADReady(interval)
    local className = 'net/ticktocklab/utils/adsmogo'
    local params = {}
    local ok, ret = luaj.callStaticMethod(className, 'isInterstitialReadyStatic', params, '()Z')
    
    return ok and ret
end

function    ADHandler:resetPopupAdTime()
    
end

function    ADHandler:showInterstitialAD()
    local className = 'net/ticktocklab/utils/adsmogo'
    local params = {}
    local ok, ret = luaj.callStaticMethod(className, 'showInterstitialStatic', params, '()V')
    
    return ok and ret
end

function    ADHandler:cancelInterstitialAD()
    local className = 'net/ticktocklab/utils/adsmogo'
    local params = {}
    local ok, ret = luaj.callStaticMethod(className, 'cancelInterstitialStatic', params, '()V')
    
    return ok and ret
end

function    ADHandler:setBarADVisible( isvisible )
    local className = 'net/ticktocklab/utils/adsmogo'
    local params = { isvisible }
    local ok, ret = luaj.callStaticMethod(className, 'showBanner', params, '(Z)V')
    
    return ok and ret
end
-----   ADColony
function G_NotifyV4vcReward(info)
    local obj = json.decode(info)
    CCLOG('V4VC result, %s, %d', obj.zoneid, obj.res)
    G_Notificaton:notify(obj.zoneid, obj.res)
    return 0;
end

function    ADHandler:isZoneReady(zoneid)
    local className = 'net/ticktocklab/utils/adVideo'
    local params = {zoneid}
    local ok, ret = luaj.callStaticMethod(className, 'isZoneReady', params, '(Ljava/lang/String;)Z')
    
    return ok and ret
end

function    ADHandler:showIVideo(zoneid)
    local className = 'net/ticktocklab/utils/adVideo'
    local params = {zoneid}
    local ok = luaj.callStaticMethod(className, 'showIVideo', params, '(Ljava/lang/String;)V')
    
    return ok
end

function    ADHandler:showV4Vc(zoneid, popup)
    local className = 'net/ticktocklab/utils/adVideo'
    local params = {zoneid, popup}
    local ok = luaj.callStaticMethod(className, 'showV4Vc', params, '(Ljava/lang/String;Z)V')
    
    return ok
end

function    ADHandler:v4vcReward(zoneid)
   return 1 
end

function    ADHandler:v4vcVideosToNextReward(zoneid)
    return 1
end


