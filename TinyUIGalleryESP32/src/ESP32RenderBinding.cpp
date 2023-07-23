#include "ESP32RenderBinding.h"
#include <lvgl.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void disp_flush(lv_disp_drv_t* disp,
                const lv_area_t* area,
                lv_color_t* color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  display.clearDisplay();
  for (uint16_t y = area->y1; y <= area->y2; y++) {
    for (uint16_t x = area->x1; x <= area->x2; x++) {
      if (color_p->full != 0) {
        display.drawPixel(x, y, WHITE);
      } else {
        display.drawPixel(x, y, BLACK);
      }
      color_p++;
    }
  }
  display.display();

  lv_disp_flush_ready(disp);
}

void ESP32RenderBinding::init() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  static lv_disp_draw_buf_t drawBuffer;
  static lv_color_t colorBuffer[128 * 64];

  lv_init();
  lv_disp_draw_buf_init(&drawBuffer, colorBuffer, nullptr, 128 * 64);

  static lv_disp_drv_t dispDry;
  lv_disp_drv_init(&dispDry);
  dispDry.hor_res = 128;
  dispDry.ver_res = 64;
  dispDry.flush_cb = disp_flush;
  dispDry.draw_buf = &drawBuffer;
  lv_disp_drv_register(&dispDry);
}

void ESP32RenderBinding::beginFrame() {
  lv_timer_handler();
}

void ESP32RenderBinding::endFrame() {}

void ESP32RenderBinding::drawPoint(const tiny::geometry::Offset& offset,
                                   const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawLine(const tiny::geometry::Offset& begin,
                                  const tiny::geometry::Offset& end,
                                  const tiny::painting::Paint& paint) {
  auto canvas = lv_canvas_create(lv_scr_act());
  lv_point_t ps[] = {{begin.dx, begin.dy}, {end.dx, end.dy}};
  lv_draw_line_dsc_t lineDsc;
  lv_draw_line_dsc_init(&lineDsc);
  lv_canvas_draw_line(canvas, ps, 2, &lineDsc);
  lv_mem_free(canvas);
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