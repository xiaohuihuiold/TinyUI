#include "ESP32RenderBinding.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <lvgl.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,
                                         /* clock=*/SCL,
                                         /* data=*/SDA,
                                         /* reset=*/U8X8_PIN_NONE);

void disp_flush(lv_disp_drv_t* disp,
                const lv_area_t* area,
                lv_color_t* color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  u8g2.clearBuffer();
  for (uint16_t y = area->y1; y <= area->y2; y++) {
    for (uint16_t x = area->x1; x <= area->x2; x++) {
      if (color_p->full != 0) {
        u8g2.drawPixel(x, y);
      }
      color_p++;
    }
  }
  u8g2.sendBuffer();
  lv_disp_flush_ready(disp);
}

void ESP32RenderBinding::init() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_profont10_mf);

  static lv_disp_draw_buf_t drawBuffer;
  static lv_color_t buffer[128 * 64];

  lv_init();
  lv_disp_draw_buf_init(&drawBuffer, buffer, nullptr, 128 * 64);

  static lv_disp_drv_t dispDry;
  lv_disp_drv_init(&dispDry);
  dispDry.hor_res = 128;
  dispDry.ver_res = 64;
  dispDry.flush_cb = disp_flush;
  dispDry.draw_buf = &drawBuffer;
  lv_disp_drv_register(&dispDry);

  static lv_style_t style1;
  lv_style_init(&style1);
  lv_style_set_border_width(&style1, 2);
  lv_style_set_text_font(&style1, &lv_font_montserrat_14);
  lv_style_set_align(&style1, LV_TEXT_ALIGN_CENTER);

  lv_obj_t* label = lv_label_create(lv_scr_act());
  lv_obj_add_style(label, &style1, LV_PART_ANY);
  lv_obj_set_pos(label, 0, 0);
  lv_obj_set_size(label, 128, 64);
  lv_label_set_text(label, "HelloWorld");
}

void ESP32RenderBinding::beginFrame() {
  lv_task_handler();
}

void ESP32RenderBinding::endFrame() {}

void ESP32RenderBinding::drawPoint(const tiny::geometry::Offset& offset,
                                   const tiny::painting::Paint& paint) {}

void ESP32RenderBinding::drawLine(const tiny::geometry::Offset& begin,
                                  const tiny::geometry::Offset& end,
                                  const tiny::painting::Paint& paint) {}

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