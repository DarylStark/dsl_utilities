#ifndef __DSL_UTILITIES_H__
#define __DSL_UTILITIES_H__

#include <chrono>
#include <functional>

namespace dsl
{
    namespace utilities
    {
        typedef std::chrono::duration<float> timediff;
        typedef std::function<void(timediff)> scopedtimer_callback_type;

        class ScopedTimer
        {
        private:
            bool __started;
            scopedtimer_callback_type __callback;
            std::chrono::_V2::system_clock::time_point __start;
            void __run_callback();

        public:
            // Constructors and destructors
            ScopedTimer(const scopedtimer_callback_type callback);
            ScopedTimer();
            ~ScopedTimer();

            // Timer functions
            void start();
            void lap();
            void stop();
        };
    };
};

#endif /* __DSL_UTILITIES_H__ */