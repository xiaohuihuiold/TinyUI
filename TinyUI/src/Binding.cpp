#include "Binding.h"

namespace tiny::binding {

    // Binding
    Binding::Binding(TimerBinding *timer) : timer(timer) {

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
