#include "BGMS.HPP"

BGMS::BGMS()
{
    BGMS_MUSC.freq = 44100;;
    BGMS_MUSC.format = AUDIO_S16SYS;
    BGMS_MUSC.channels = 2;
    BGMS_MUSC.silence = 0;
    BGMS_MUSC.samples = 1024;;
    BGMS_MUSC.callback = 0;
    BGMS_MUSC.userdata = NULL;
}
