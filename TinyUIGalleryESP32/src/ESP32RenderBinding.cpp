#include "ESP32RenderBinding.h"

void ESP32RenderBinding::init() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
}
void ESP32RenderBinding::beginFrame() {
  display.clearDisplay();
}

void ESP32RenderBinding::endFrame() {
  display.display();
}

void ESP32RenderBinding::drawPoint(const tiny::geometry::Offset& offset,
                                   const tiny::painting::Paint& paint) {
  display.drawPixel(offset.dx, offset.dy, static_cast<uint16_t>(paint.color));
}

void ESP32RenderBinding::drawLine(const tiny::geometry::Offset& begin,
                                  const tiny::geometry::Offset& end,
                                  const tiny::painting::Paint& paint) {
  display.drawLine(begin.dx, begin.dy, end.dx, end.dy,
                   static_cast<uint16_t>(paint.color));
}

void ESP32RenderBinding::drawRect(const tiny::geometry::Rect& rect,
                                  const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawRRect(const tiny::geometry::RRect& rRect,
                                   const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawCircle(const tiny::geometry::Offset& offset,
                                    float radius,
                                    const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawOval(const tiny::geometry::Rect& rect,
                                  const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawArc(const tiny::geometry::Rect& rect,
                                 float beginAngle,
                                 float endAngle,
                                 const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawPath(const tiny::path::Path& path,
                                  const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::save() {}

void ESP32RenderBinding::restore() {}

void ESP32RenderBinding::clipRect(const tiny::geometry::Rect& rect,
                                  tiny::painting::ClipOp clipOp) {}

void ESP32RenderBinding::clipRRect(const tiny::geometry::RRect& rRect,
                                   tiny::painting::ClipOp clipOp) {}

void ESP32RenderBinding::clipCircle(const tiny::geometry::Offset& offset,
                                    float radius,
                                    tiny::painting::ClipOp clipOp) {}

void ESP32RenderBinding::clipOval(const tiny::geometry::Rect& rect,
                                  tiny::painting::ClipOp clipOp) {}

void ESP32RenderBinding::clipPath(const tiny::path::Path& path) {}

void ESP32RenderBinding::translate(const tiny::geometry::Offset& offset) {}

void ESP32RenderBinding::rotate(float angle) {}

void ESP32RenderBinding::rotate(float angle,
                                const tiny::geometry::Offset& anchor) {}

void ESP32RenderBinding::scale(float scaleX, float scaleY) {}

void ESP32RenderBinding::scale(float scaleX,
                               float scaleY,
                               const tiny::geometry::Offset& anchor) {}