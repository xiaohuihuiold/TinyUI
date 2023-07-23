#ifndef TINYUI_PAINTING_H
#define TINYUI_PAINTING_H

#include <cstdint>

namespace tiny {

    class TinyUI;

    namespace path {
        class Path;
    }

    namespace painting {

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
            TinyUI *tinyUI = nullptr;

        public:
            explicit Canvas(TinyUI *tiny);

            void drawPoint(const geometry::Offset &offset, const Paint &paint);

            void
            drawLine(const geometry::Offset &begin, const geometry::Offset &end, const Paint &paint);

            void drawRect(const geometry::Rect &rect, const Paint &paint);

            void drawRRect(const geometry::RRect &rRect, const Paint &paint);

            void drawCircle(const geometry::Offset &offset, float radius, const Paint &paint);

            void drawOval(const geometry::Rect &rect, const Paint &paint);

            void
            drawArc(const geometry::Rect &rect, float beginAngle, float endAngle, const Paint &paint);

            void drawPath(const path::Path &path, const Paint &paint);

            void save();

            void restore();

            void clipRect(const geometry::Rect &rect, ClipOp clipOp);

            void clipRRect(const geometry::RRect &rRect, ClipOp clipOp);

            void clipCircle(const geometry::Offset &offset, float radius, ClipOp clipOp);

            void clipOval(const geometry::Rect &rect, ClipOp clipOp);

            void clipPath(const path::Path &path);

            void translate(const geometry::Offset &offset);

            void rotate(float angle);

            void rotate(float angle, const geometry::Offset &anchor);

            void scale(float scaleX, float scaleY);

            void scale(float scaleX, float scaleY, const geometry::Offset &anchor);
        };

    } // painting
} // tiny

#endif //TINYUI_PAINTING_H
