#include "Binding.h"

#include <utility>

namespace tiny::binding {

    // Binding
    Binding::Binding(std::shared_ptr<TimerBinding> timer, std::shared_ptr<RenderBinding> render) : timer(
            std::move(timer)), render(std::move(render)) {
        this->render->init();
    }

    // RenderBinding
    void RenderBinding::rotate(float angle, const geometry::Offset &anchor) {
        translate(anchor);
        rotate(angle);
        translate(-anchor);
    }

    void RenderBinding::scale(float scaleX, float scaleY, const geometry::Offset &anchor) {
        translate(anchor);
        scale(scaleX, scaleY);
        translate(-anchor);
    }
}
