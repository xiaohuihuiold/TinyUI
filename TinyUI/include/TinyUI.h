#ifndef TINYUI_TINYUI_H
#define TINYUI_TINYUI_H

#include <memory>
#include "Binding.h"

namespace tiny {

    class TinyUI {
    private:
        static TinyUI *instance;

    public:
        const std::shared_ptr<binding::Binding> binding;

    private:
        explicit TinyUI(std::shared_ptr<binding::Binding> binding);

    public:
        static TinyUI *begin(std::shared_ptr<binding::TimerBinding> timerBinding,
                             std::shared_ptr<binding::RenderBinding> renderBinding);

        [[nodiscard]]
        static TinyUI *get();

        [[nodiscard]]
        std::shared_ptr<painting::Canvas> beginCanvas();

        void beginFrame();

        void endFrame();
    };

} // tiny

#endif
