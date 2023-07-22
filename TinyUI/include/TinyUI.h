#ifndef TINYUI_TINYUI_H
#define TINYUI_TINYUI_H

#include <memory>
#include "Binding.h"

namespace tiny {

    class TinyUI {
    private:
        static TinyUI *instance;
        std::shared_ptr<binding::Binding> mBinding;

    private:
        explicit TinyUI(binding::Binding *binding);

    public:
        static TinyUI *begin(binding::TimerBinding *timerBinding);

        [[nodiscard]]
        static TinyUI *get();

        [[nodiscard]]
        std::shared_ptr<binding::Binding> binding();
    };

} // tiny

#endif
