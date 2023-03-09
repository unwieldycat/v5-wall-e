#include "gui.h"

// =============================== Variables =============================== //

lv_style_t title_style;
lv_style_t cont_style;
lv_style_t bar_style;
lv_style_t bar_style_on;
lv_style_t btn_style;
lv_style_t btn_style_pr;

std::vector<lv_obj_t*> bars;

// ======================== Battery Widget Functions ======================== //

void battery_anim() {
  int battery_pct = Brain.Battery.capacity();
  int pct_appx = round(battery_pct) / 10;

  double wait_time = 1000;
  for (int i = 0; i < bars.size(); i++) {
    vex::wait(wait_time, vex::timeUnits::msec);
    lv_obj_t * bar = bars.at(i);
    lv_obj_add_style(bar, &bar_style_on, LV_PART_MAIN);

    if (pct_appx <= i) break;
    if (i == 2) wait_time = 100;
  }
}

void gui::battery_task() {
  battery_anim();

  while(true) {
    int battery_pct = Brain.Battery.capacity();
    int pct_appx = round(battery_pct) / 10;

    for (int i = 0; i < bars.size(); i++) {
      lv_obj_t * bar = bars.at(i);
      if (pct_appx >= i) continue;
      lv_obj_remove_style(bar, &bar_style_on, LV_PART_MAIN);

      // TODO: Add red flashing warning on bottom bar if battery is low
    }

    vex::wait(10, vex::timeUnits::sec);
  }
}

// ========================= Mode Selector Callback ========================= //

static void auton_tgl_cb(lv_event_t * event){
  // TODO: Handle auton toggle
}

// ============================= Initialization ============================= //

void gui::init() {
  lv_disp_set_rotation(lv_disp_get_default(), LV_DISP_ROT_90);

  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x000000), LV_PART_MAIN);

  lv_style_set_text_color(&title_style, MAIN_COLOR);
  lv_style_set_text_font(&title_style, &lv_font_montserrat_20);
  lv_style_set_text_align(&title_style, LV_TEXT_ALIGN_CENTER);

  lv_obj_t *charge_label = lv_label_create(lv_scr_act());
  lv_obj_add_style(charge_label, &title_style, LV_PART_MAIN);
  lv_label_set_text(charge_label, "SOLAR CHARGE LEVEL");
  lv_obj_align(charge_label, LV_ALIGN_TOP_MID, 0, 16);

  lv_obj_t *img = lv_img_create(lv_scr_act());
  lv_img_set_src(img, &indicator);
  lv_obj_align(img, LV_ALIGN_TOP_LEFT, 4, 60);
  
  lv_style_set_bg_opa(&cont_style, 0);
  lv_style_set_border_opa(&cont_style, 0);
  lv_style_set_pad_hor(&cont_style, 0);
  lv_style_set_pad_ver(&cont_style, 8);
  lv_style_set_pad_row(&cont_style, 16);

  lv_obj_t *bar_cont = lv_obj_create(lv_scr_act());
  lv_obj_add_style(bar_cont, &cont_style, LV_PART_MAIN);
  lv_obj_set_size(bar_cont, 160, 420);
  lv_obj_align(bar_cont, LV_ALIGN_TOP_RIGHT, -4, 52);
  lv_obj_set_layout(bar_cont, LV_LAYOUT_FLEX);
  lv_obj_set_flex_flow(bar_cont, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(bar_cont, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_style_set_radius(&bar_style, 0);
  lv_style_set_border_opa(&bar_style, LV_OPA_0);
  lv_style_set_bg_color(&bar_style, INA_COLOR);
  
  lv_style_set_shadow_color(&bar_style_on, MAIN_COLOR);
  lv_style_set_shadow_width(&bar_style_on, LV_DPX(15));
  lv_style_set_shadow_spread(&bar_style_on, LV_DPX(5));
  lv_style_set_bg_color(&bar_style_on, MAIN_COLOR);

  for (int i = 0; i < 10; i++) {
    lv_obj_t *bar = lv_obj_create(bar_cont);
    lv_obj_add_style(bar, &bar_style, LV_PART_MAIN);
    lv_obj_set_scrollbar_mode(bar, LV_SCROLLBAR_MODE_OFF);
    bars.insert(bars.begin(), bar);

    if (i == 9)
      lv_obj_set_size(bar, 144, 24);
    else
      lv_obj_set_size(bar, 144, 10);
  }

  lv_obj_t *functions_label = lv_label_create(lv_scr_act());
  lv_obj_add_style(functions_label, &title_style, LV_PART_MAIN);
  lv_label_set_text(functions_label, "FUNCTIONS");
  lv_obj_align(functions_label, LV_ALIGN_BOTTOM_MID, 0, -110);

  lv_style_set_bg_color(&btn_style, lv_color_hex(0x000000));
  lv_style_set_radius(&btn_style, 0);
  lv_style_set_text_color(&btn_style, MAIN_COLOR);
  lv_style_set_border_color(&btn_style, MAIN_COLOR);
  lv_style_set_border_width(&btn_style, 1);

  lv_style_set_text_color(&btn_style_pr, lv_color_hex(0x000000));
  lv_style_set_bg_color(&btn_style_pr, MAIN_COLOR);

  lv_obj_t *auton_btn = lv_btn_create(lv_scr_act());
  lv_obj_add_style(auton_btn, &btn_style, LV_PART_MAIN);
  lv_obj_add_style(auton_btn, &btn_style_pr, LV_STATE_CHECKED);
  lv_obj_add_flag(auton_btn, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_add_event_cb(auton_btn, auton_tgl_cb, LV_EVENT_VALUE_CHANGED, NULL);
  lv_obj_set_size(auton_btn, 224, 32);
  lv_obj_align(auton_btn, LV_ALIGN_BOTTOM_MID, 0, -8);

  lv_obj_t *auton_btn_label = lv_label_create(auton_btn);
  lv_label_set_text(auton_btn_label, "Enable Auton Mode");
  lv_obj_align(auton_btn_label, LV_ALIGN_CENTER, 0, 0);
}