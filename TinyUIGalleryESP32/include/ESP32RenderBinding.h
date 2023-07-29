#ifndef GALLERY_ESP32RENDERBINDING_H
#define GALLERY_ESP32RENDERBINDING_H

#include <TinyUI.h>

class ESP32RenderBinding : public tiny::binding::RenderBinding {
 public:
  void init() override;

  void beginFrame() override;

  void endFrame() override;

  void drawPoint(const tiny::geometry::Offset& offset,
                 const tiny::painting::Paint& paint) override;

  void drawLine(const tiny::geometry::Offset& begin,
                const tiny::geometry::Offset& end,
                const tiny::painting::Paint& paint) override;

  void drawRect(const tiny::geometry::Rect& rect,
                const tiny::painting::Paint& paint) override;

  void drawRRect(const tiny::geometry::RRect& rRect,
                 const tiny::painting::Paint& paint) override;

  void drawCircle(const tiny::geometry::Offset& offset,
                  float radius,
                  const tiny::painting::Paint& paint) override;

  void drawOval(const tiny::geometry::Rect& rect,
                const tiny::painting::Paint& paint) override;

  void drawArc(const tiny::geometry::Rect& rect,
               float beginAngle,
               float endAngle,
               const tiny::painting::Paint& paint) override;

  void drawPath(const tiny::path::Path& path,
                const tiny::painting::Paint& paint) override;

  void save() override;

  void restore() override;

  void clipRect(const tiny::geometry::Rect& rect,
                tiny::painting::ClipOp clipOp) override;

  void clipRRect(const tiny::geometry::RRect& rRect,
                 tiny::painting::ClipOp clipOp) override;

  void clipCircle(const tiny::geometry::Offset& offset,
                  float radius,
                  tiny::painting::ClipOp clipOp) override;

  void clipOval(const tiny::geometry::Rect& rect,
                tiny::painting::ClipOp clipOp) override;

  void clipPath(const tiny::path::Path& path) override;

  void translate(const tiny::geometry::Offset& offset) override;

  void rotate(float angle) override;

  void rotate(float angle, const tiny::geometry::Offset& anchor) override;

  void scale(float scaleX, float scaleY) override;

  void scale(float scaleX,
             float scaleY,
             const tiny::geometry::Offset& anchor) override;
};

#endif