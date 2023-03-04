# v5-wall-e
Source code for 877's off-season Wall-E robot.

## Contributing
**This project uses [VEXCode Pro](https://www.vexrobotics.com/vexcode/pro-v5), not to be confused with VEXCode, VEX VSCode, or PROS.**

### Building
1. Clone the repository
2. Open the project manifest with VEXCode Pro
3. Invoke the build action in the topbar.

### Adding Devices
Expert mode is enabled in this project, meaning you will have to add motors and other devices manually.
To add a device:
1. Declare it in `devices.h`
```
extern vex::motor Motor;
```
2. Define it in `devices.cpp`
```
vex::motor Motor(1);
```
To use a device in another file, make sure to `#include "devices.h"` at the top.

### Other stuff
- Try to run the formatter somewhat often as to not cause more than one indentation type or other inconsistencies
- This project uses [LVGL 7.11](https://docs.lvgl.io/7.11/index.html) because jpearman's lvgl 8 port is broken (so no flexbox :<)
- You should use [GitHub Desktop](https://desktop.github.com/) to sync changes
