#ifndef TINYUI_GEOMETRY_H
#define TINYUI_GEOMETRY_H

#include <cstdint>

namespace tiny::geometry {

    class Offset {
    public:
        const int dx;
        const int dy;

    public:
        Offset(int dx, int dy);

        Offset operator-() const;
    };

    class Rect {
    public:
        const int left;
        const int top;
        const int right;
        const int bottom;

    public:
        Rect(int left, int top, int right, int bottom);
    };

    class RRect {
    public:
        const Rect rect;
        const float radius;

    public:
        RRect(Rect rect, float radius);
    };
} // geometry

#endif //TINYUI_GEOMETRY_H
