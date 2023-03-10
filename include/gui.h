#include "devices.h"
#include "resources/indicator.h"
#include "vex.h"

#define MAIN_COLOR lv_color_hex(0xfafa02)
#define INA_COLOR lv_color_hex(0x262626)

namespace gui {
/**
 * Initialize GUI
 */
void init();

/**
 * Task for updating battery widget on UI
 */
void battery_task();

} // namespace gui
