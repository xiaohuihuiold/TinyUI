#include "TinyUI.h"
#include "Painting.h"

namespace tiny::painting {

    Canvas::Canvas(TinyUI *tiny) : tinyUI(tiny) {

    }

    void Canvas::drawPoint(const geometry::Offset &offset, const Paint &paint) {
        tinyUI->binding->render->drawPoint(offset, paint);
    }

    void Canvas::drawLine(const geometry::Offset &begin, const geometry::Offset &end, const Paint &paint) {
        tinyUI->binding->render->drawLine(begin, end, paint);
    }

    void Canvas::drawRect(const geometry::Rect &rect, const Paint &paint) {
        tinyUI->binding->render->drawRect(rect, paint);
    }

    void Canvas::drawRRect(const geometry::RRect &rRect, const Paint &paint) {
        tinyUI->binding->render->drawRRect(rRect, paint);
    }

    void Canvas::drawCircle(const geometry::Offset &offset, float radius, const Paint &paint) {
        tinyUI->binding->render->drawCircle(offset, radius, paint);
    }

    void Canvas::drawOval(const geometry::Rect &rect, const Paint &paint) {
        tinyUI->binding->render->drawOval(rect, paint);
    }

    void Canvas::drawArc(const geometry::Rect &rect, float beginAngle, float endAngle, const Paint &paint) {
        tinyUI->binding->render->drawArc(rect, beginAngle, endAngle, paint);
    }

    void Canvas::drawPath(const path::Path &path, const Paint &paint) {
        tinyUI->binding->render->drawPath(path, paint);
    }

    void Canvas::save() {
        tinyUI->binding->render->save();
    }

    void Canvas::restore() {
        tinyUI->binding->render->restore();
    }

    void Canvas::clipRect(const geometry::Rect &rect, ClipOp clipOp) {
        tinyUI->binding->render->clipRect(rect, clipOp);
    }

    void Canvas::clipRRect(const geometry::RRect &rRect, ClipOp clipOp) {
        tinyUI->binding->render->clipRRect(rRect, clipOp);
    }

    void Canvas::clipCircle(const geometry::Offset &offset, float radius, ClipOp clipOp) {
        tinyUI->binding->render->clipCircle(offset, radius, clipOp);
    }

    void Canvas::clipOval(const geometry::Rect &rect, ClipOp clipOp) {
        tinyUI->binding->render->clipOval(rect, clipOp);
    }

    void Canvas::clipPath(const path::Path &path) {
        tinyUI->binding->render->clipPath(path);
    }

    void Canvas::translate(const geometry::Offset &offset) {
        tinyUI->binding->render->translate(offset);
    }

    void Canvas::rotate(float angle) {
        tinyUI->binding->render->rotate(angle);
    }

    void Canvas::rotate(float angle, const geometry::Offset &anchor) {
        tinyUI->binding->render->rotate(angle, anchor);
    }

    void Canvas::scale(float scaleX, float scaleY) {
        tinyUI->binding->render->scale(scaleX, scaleY);
    }

    void Canvas::scale(float scaleX, float scaleY, const geometry::Offset &anchor) {
        tinyUI->binding->render->scale(scaleX, scaleY, anchor);
    }

}
