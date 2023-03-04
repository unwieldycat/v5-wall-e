#include "gui.h"

void init_gui() {
  static lv_style_t title_style;
  lv_style_set_text_color(&title_style, LV_STATE_DEFAULT, MAIN_COLOR);
  lv_style_set_text_font(&title_style, LV_STATE_DEFAULT, &lv_font_montserrat_20);

  lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
  lv_obj_add_style(label, 0, &title_style);
  lv_label_set_align(label, LV_ALIGN_CENTER);
  lv_label_set_text(label, "SOLAR CHARGE LEVEL");
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 16);

  lv_obj_t *img = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img, &indicator);
  lv_obj_align(img, NULL, LV_ALIGN_IN_TOP_LEFT, 4, 60);

  static lv_style_t cont_style;
  lv_style_set_bg_opa(&cont_style, LV_STATE_DEFAULT, 0);
  lv_style_set_border_opa(&cont_style, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_hor(&cont_style, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_ver(&cont_style, LV_STATE_DEFAULT, 8);

  lv_obj_t *bar_cont = lv_cont_create(lv_scr_act(), NULL);
  lv_obj_add_style(bar_cont, LV_CONT_PART_MAIN, &cont_style);
  lv_obj_set_size(bar_cont, 160, 420);
  lv_obj_align(bar_cont, NULL, LV_ALIGN_IN_TOP_RIGHT, -4, 52);
  lv_cont_set_layout(bar_cont, LV_LAYOUT_COLUMN_MID);

  static lv_style_t bar_style;
  lv_style_set_radius(&bar_style, LV_STATE_DEFAULT, 0);
  lv_style_set_shadow_color(&bar_style, LV_STATE_DEFAULT, MAIN_COLOR);
  lv_style_set_shadow_width(&bar_style, LV_STATE_DEFAULT, LV_DPX(15));
  lv_style_set_shadow_spread(&bar_style, LV_STATE_DEFAULT, LV_DPX(5));
  lv_style_set_bg_color(&bar_style, LV_STATE_DEFAULT, MAIN_COLOR);

  for (int i = 0; i < 10; i++) {
    lv_obj_t *bar = lv_obj_create(bar_cont, NULL);
    lv_obj_add_style(bar, LV_OBJ_PART_MAIN, &bar_style);

    if (i == 9)
      lv_obj_set_size(bar, 144, 24);
    else
      lv_obj_set_size(bar, 144, 10);
  }
}