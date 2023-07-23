#ifndef TINYUI_PAINTING_H
#define TINYUI_PAINTING_H

#include <cstdint>
#include "TinyUI.h"

namespace tiny::painting {

    enum class ClipOp {
        difference = 0,
        intersect = 1,
    };

    enum class Colors {
        black = 0,
        white = 1,
        inverse = 2,
    };

    struct Paint {
        Colors color = Colors::white;
        int strokeWidth = 1;
    };

    class Canvas {
    private:
        TinyUI *tiny = nullptr;

    public:
        explicit Canvas(TinyUI *tiny);

        void drawPoint(const geometry::Offset &offset, const painting::Paint &paint);

        void
        drawLine(const geometry::Offset &begin, const geometry::Offset &end, const painting::Paint &paint);

        void drawRect(const geometry::Rect &rect, const painting::Paint &paint);

        void drawRRect(const geometry::RRect &rRect, const painting::Paint &paint);

        void drawCircle(const geometry::Offset &offset, float radius, const painting::Paint &paint);

        void drawOval(const geometry::Rect &rect, const painting::Paint &paint);

        void
        drawArc(const geometry::Rect &rect, float beginAngle, float endAngle, const painting::Paint &paint);

        void drawPath(const path::Path &path, const painting::Paint &paint);

        void save();

        void restore();

        void clipRect(const geometry::Rect &rect, painting::ClipOp clipOp);

        void clipRRect(const geometry::RRect &rRect, painting::ClipOp clipOp);

        void clipCircle(const geometry::Offset &offset, float radius, painting::ClipOp clipOp);

        void clipOval(const geometry::Rect &rect, painting::ClipOp clipOp);

        void clipPath(const path::Path &path);

        void translate(const geometry::Offset &offset);

        void rotate(float angle);

        void rotate(float angle, const geometry::Offset &anchor);

        void scale(float scaleX, float scaleY);

        void scale(float scaleX, float scaleY, const geometry::Offset &anchor);
    };

} // painting

#endif //TINYUI_PAINTING_H
