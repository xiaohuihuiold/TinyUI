#ifndef TINYUI_BINDING_H
#define TINYUI_BINDING_H

#include <cstdint>
#include <memory>

namespace tiny::binding {

    class TimerBinding {
    public:
        /// 微秒
        virtual int64_t getTime() = 0;
    };

    class Binding {
    private:
        std::shared_ptr<TimerBinding> mTimer;
    public:
        explicit Binding(TimerBinding *timer);

        std::shared_ptr<TimerBinding> timer();
    };

} // tiny

#endif
