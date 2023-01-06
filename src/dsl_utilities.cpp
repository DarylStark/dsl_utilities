#include "dsl_utilities.h"

namespace dsl
{
    namespace utilities
    {
        ScopedTimer::ScopedTimer(const scopedtimer_callback_type callback)
            : __callback(callback), __started(true), __start(std::chrono::high_resolution_clock::now())
        {
        }

        ScopedTimer::ScopedTimer()
            : __started(true), __start(std::chrono::high_resolution_clock::now())
        {
        }

        void ScopedTimer::stop()
        {
            if (!__started)
                return;

            std::chrono::_V2::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            if (__callback)
                __callback(now - __start);
            __started = false;
        }

        ScopedTimer::~ScopedTimer()
        {
            stop();
        }
    }
}
