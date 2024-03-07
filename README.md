# v5-wall-e

Source code for 877's off-season Wall-E robot.

## Contributing

**This project uses [the VSCode VEX Robotics Extension](https://www.vexrobotics.com/vexcode/vscode-extension)**

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

### LVGL Stuff

- If LVGL is rebuilt to be updated, enable software display rotation and all fonts. [Link to library for V5](https://github.com/jpearman/vexcode-lvgllib8_X)
- If mkrules.mk is ever overwritten, ensure the following:
  - `-L.` is placed at the end of `LNK_FLAGS` - this tells gcc to look in the root directory for library files
  - `-lv5lvgl` is somewhere inside of `LIBS` - this adds the library to the executable
