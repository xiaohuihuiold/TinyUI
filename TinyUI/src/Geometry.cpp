#include "Geometry.h"

namespace tiny::geometry {

    // Offset
    Offset::Offset(int dx, int dy) : dx(dx), dy(dy) {
    }

    Offset Offset::operator-() const {
        return {-dx, -dy};
    }

    // Rect
    Rect::Rect(int left, int top, int right, int bottom) : left(left), top(top), right(right),
                                                           bottom(bottom) {
    }

    // RRect
    RRect::RRect(Rect rect, float radius) : rect(rect), radius(radius) {
    }

}
