#include "Binding.h"

namespace tiny::binding {
    Binding::Binding(TimerBinding *timer) : mTimer(timer) {

    }

    std::shared_ptr<TimerBinding> Binding::timer() {
        return mTimer;
    }

}
