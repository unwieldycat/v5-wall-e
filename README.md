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

### Other stuff

- Try to run the formatter somewhat often as to not cause more than one indentation type or other inconsistencies
- You should use [GitHub Desktop](https://desktop.github.com/) to sync changes
- If LVGL is rebuilt to be updated, enable software display rotation and all fonts. [Link to library for V5](https://github.com/jpearman/vexcode-lvgllib8_X)
