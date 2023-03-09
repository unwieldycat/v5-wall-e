#include "vex.h"
#include "gui.h"
#include "devices.h"

int main() {
  v5_lv_init();
  gui::init();

  vex::thread gui_bat_thread(gui::battery_task);
  vex::thread drive_thread(drive);
}
