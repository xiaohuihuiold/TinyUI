#ifndef TINYUI_BINDING_H
#define TINYUI_BINDING_H

#include <cstdint>
#include <memory>
#include "Geometry.h"
#include "Painting.h"
#include "Path.h"

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

        virtual void beginFrame() = 0;

        virtual void endFrame() = 0;

        virtual void drawPoint(const geometry::Offset &offset, const painting::Paint &paint) = 0;

        virtual void
        drawLine(const geometry::Offset &begin, const geometry::Offset &end, const painting::Paint &paint) = 0;

        virtual void drawRect(const geometry::Rect &rect, const painting::Paint &paint) = 0;

        virtual void drawRRect(const geometry::RRect &rRect, const painting::Paint &paint) = 0;

        virtual void drawCircle(const geometry::Offset &offset, float radius, const painting::Paint &paint) = 0;

        virtual void drawOval(const geometry::Rect &rect, const painting::Paint &paint) = 0;

        virtual void
        drawArc(const geometry::Rect &rect, float beginAngle, float endAngle, const painting::Paint &paint) = 0;

        virtual void drawPath(const path::Path &path, const painting::Paint &paint) = 0;

        virtual void save() = 0;

        virtual void restore() = 0;

        virtual void clipRect(const geometry::Rect &rect, painting::ClipOp clipOp) = 0;

        virtual void clipRRect(const geometry::RRect &rRect, painting::ClipOp clipOp) = 0;

        virtual void clipCircle(const geometry::Offset &offset, float radius, painting::ClipOp clipOp) = 0;

        virtual void clipOval(const geometry::Rect &rect, painting::ClipOp clipOp) = 0;

        virtual void clipPath(const path::Path &path) = 0;

        virtual void translate(const geometry::Offset &offset) = 0;

        virtual void rotate(float angle) = 0;

        virtual void rotate(float angle, const geometry::Offset &anchor);

        virtual void scale(float scaleX, float scaleY) = 0;

        virtual void scale(float scaleX, float scaleY, const geometry::Offset &anchor);
    };

    class Binding {
    public:
        const std::shared_ptr<TimerBinding> timer;
        const std::shared_ptr<RenderBinding> render;

    public:
        explicit Binding(std::shared_ptr<TimerBinding> timer, std::shared_ptr<RenderBinding> render);
    };

} // binding

#endif
