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
        virtual int64_t getTime() = 0;
    };

    class RenderBinding {
    public:
        virtual void init() = 0;

        virtual void drawPoint(geometry::Offset offset, const painting::Paint *paint) = 0;

        virtual void drawLine(geometry::Offset begin, geometry::Offset end, const painting::Paint *paint) = 0;

        virtual void drawRect(const geometry::Rect *rect, const painting::Paint *paint) = 0;

        virtual void drawRRect(const geometry::RRect *rRect, const painting::Paint *paint) = 0;
    };

    class Binding {
    private:
        std::shared_ptr<TimerBinding> mTimer;
    public:
        explicit Binding(TimerBinding *timer);

        std::shared_ptr<TimerBinding> timer();
    };

} // binding

#endif
