#include "gui.h"

void init_gui() {
  lv_disp_set_rotation(lv_disp_get_default(), LV_DISP_ROT_90);

  static lv_style_t title_style;
  lv_style_set_text_color(&title_style, MAIN_COLOR);
  lv_style_set_text_font(&title_style, &lv_font_montserrat_20);
  lv_style_set_text_align(&title_style, LV_TEXT_ALIGN_CENTER);

  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_obj_add_style(label, &title_style, LV_PART_MAIN);
  lv_label_set_text(label, "SOLAR CHARGE LEVEL");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 16);

  lv_obj_t *img = lv_img_create(lv_scr_act());
  lv_img_set_src(img, &indicator);
  lv_obj_align(img, LV_ALIGN_TOP_LEFT, 4, 60);

  static lv_style_t cont_style;
  lv_style_set_bg_opa(&cont_style, 0);
  lv_style_set_border_opa(&cont_style, 0);
  lv_style_set_pad_hor(&cont_style, 0);
  lv_style_set_pad_ver(&cont_style, 8);

  lv_obj_t *bar_cont = lv_obj_create(lv_scr_act());
  lv_obj_add_style(bar_cont, &cont_style, LV_PART_MAIN);
  lv_obj_set_size(bar_cont, 160, 420);
  lv_obj_align(bar_cont, LV_ALIGN_TOP_RIGHT, -4, 52);
  lv_obj_set_layout(bar_cont, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(bar_cont, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(bar_cont, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  static lv_style_t bar_style;
  lv_style_set_radius(&bar_style, 0);
  lv_style_set_shadow_color(&bar_style, MAIN_COLOR);
  lv_style_set_shadow_width(&bar_style, LV_DPX(15));
  lv_style_set_shadow_spread(&bar_style, LV_DPX(5));
  lv_style_set_border_opa(&bar_style, LV_OPA_0);
  lv_style_set_bg_color(&bar_style, MAIN_COLOR);

  for (int i = 0; i < 10; i++) {
    lv_obj_t *bar = lv_obj_create(bar_cont);
    lv_obj_add_style(bar, &bar_style, LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(bar, LV_SCROLLBAR_MODE_OFF);

    if (i == 9)
      lv_obj_set_size(bar, 144, 24);
    else
      lv_obj_set_size(bar, 144, 10);
  }
}