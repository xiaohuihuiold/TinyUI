#include "Geometry.h"

namespace tiny::geometry {

    Offset::Offset(int16_t dx, int16_t dy) : mDx(dx), mDy(dy) {

    }

    int16_t Offset::dx() const {
        return mDx;
    }

    int16_t Offset::dy() const {
        return mDy;
    }

    Rect::Rect(int16_t left, int16_t top, int16_t right, int16_t bottom) : mLeft(left), mTop(top), mRight(right),
                                                                           mBottom(bottom) {

    }

    int16_t Rect::left() const {
        return mLeft;
    }

    int16_t Rect::top() const {
        return mTop;
    }

    int16_t Rect::right() const {
        return mRight;
    }

    int16_t Rect::bottom() const {
        return mBottom;
    }

    RRect::RRect(const Rect *rect, int16_t radius) : mRect(rect), mRadius(radius) {

    }

    const Rect *RRect::rect() const {
        return mRect;
    }

    int16_t RRect::radius() const {
        return mRadius;
    }

}
