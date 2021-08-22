#include "plugin.h"
#include "CClock.h"
#include "time.h"

using namespace plugin;

class RealTime {
public:
    RealTime() {
        // Initialise your plugin here
        Events::gameProcessEvent += [] {
            time_t now_time = time(NULL);
            tm* t_tm = localtime(&now_time);
            if (CClock::ms_nGameClockHours == t_tm->tm_hour && CClock::ms_nGameClockMinutes == t_tm->tm_min) {
                return;
            }
            CClock::SetGameClock(t_tm->tm_hour, t_tm->tm_min);
            CClock::ms_nMillisecondsPerGameMinute = 60000; // by default: 1000ms in real world  =  1min in game 
        };
    }
} realTime;
