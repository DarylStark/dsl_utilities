#include "dsl_scoped_timer.h"

namespace dsl
{
    namespace utilities
    {
        ScopedTimer::ScopedTimer(const scopedtimer_callback_type callback)
            : __callback(callback)
        {
            start();
        }

        ScopedTimer::ScopedTimer()
        {
            start();
        }

        ScopedTimer::~ScopedTimer()
        {
            stop();
        }

        void ScopedTimer::__run_callback()
        {
            std::chrono::_V2::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
            if (__callback)
                __callback(now - __start);
        }

        void ScopedTimer::start()
        {
            __started = true;
            __start = std::chrono::high_resolution_clock::now();
        }

        void ScopedTimer::lap()
        {
            if (!__started)
                return;
            __run_callback();
        }

        void ScopedTimer::stop()
        {
            if (!__started)
                return;
            __run_callback();
            __started = false;
        }
    }
}
