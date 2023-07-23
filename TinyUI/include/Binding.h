#ifndef TINYUI_BINDING_H
#define TINYUI_BINDING_H

#include <cstdint>
#include <memory>
#include "Geometry.h"
#include "Painting.h"

namespace tiny::binding {

    class TimerBinding {
    public:
        /// 微秒
        [[nodiscard]]
        virtual int64_t getTime() = 0;
    };

    class RenderBinding {
    public:
        virtual void init() = 0;

        virtual void drawPoint(const geometry::Offset &offset, const painting::Paint &paint) = 0;

        virtual void
        drawLine(const geometry::Offset &begin, const geometry::Offset &end, const painting::Paint &paint) = 0;

        virtual void drawRect(const geometry::Rect &rect, const painting::Paint &paint) = 0;

        virtual void drawRRect(const geometry::RRect &rRect, const painting::Paint &paint) = 0;

        virtual void drawCircle(const geometry::Offset &offset, float radius, const painting::Paint &paint) = 0;

        virtual void drawOval(const geometry::Rect &rect, const painting::Paint &paint) = 0;

        virtual void
        drawArc(const geometry::Rect &rect, float beginAngle, float endAngle, const painting::Paint &paint) = 0;

        virtual void save() = 0;

        virtual void restore() = 0;

        virtual void translate(const geometry::Offset &offset) = 0;

        virtual void rotate(float angle) = 0;

        virtual void rotate(float angle, const geometry::Offset &anchor);

        virtual void scale(float scaleX, float scaleY) = 0;

        virtual void scale(float scaleX, float scaleY, const geometry::Offset &anchor);
    };

    class Binding {
    public:
        const std::shared_ptr<TimerBinding> timer;

    public:
        explicit Binding(TimerBinding *timer);
    };

} // binding

#endif
