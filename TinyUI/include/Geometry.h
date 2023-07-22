#ifndef TINYUI_GEOMETRY_H
#define TINYUI_GEOMETRY_H

#include <cstdint>

namespace tiny::geometry {

    class Offset {
    private:
        int16_t mDx;
        int16_t mDy;

    public:
        Offset(int16_t dx, int16_t dy);

        [[nodiscard]]
        int16_t dx() const;

        [[nodiscard]]
        int16_t dy() const;

    };

    class Rect {
    private:
        int16_t mLeft;
        int16_t mTop;
        int16_t mRight;
        int16_t mBottom;

    public:
        Rect(int16_t left, int16_t top, int16_t right, int16_t bottom);

        [[nodiscard]]
        int16_t left() const;

        [[nodiscard]]
        int16_t top() const;

        [[nodiscard]]
        int16_t right() const;

        [[nodiscard]]
        int16_t bottom() const;

    };

    class RRect {
    private:
        const Rect *mRect;
        int16_t mRadius;

    public:
        RRect(const Rect *rect, int16_t radius);

        [[nodiscard]]
        const Rect *rect() const;

        [[nodiscard]]
        int16_t radius() const;
    };
} // geometry

#endif //TINYUI_GEOMETRY_H
