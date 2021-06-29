## PSoC uGui: Adding graphics to Cypress PSoC microcontrollers. ##

For one of my projects i need to add one of those 1.8" cheap graphics display. For the project, i am using the uGui library developed by Achim Döbler.
You can find information about uGui in his webpage:

* Webpage: http://www.embeddedlightning.com/ugui/
* Reference guide for uGui: http://www.embeddedlightning.com/download/reference-guide/?wpdmdl=205
* Git: https://github.com/achimdoebler/UGUI


### Repository. ###
* PSoC_uGui_Library: uGui library.
* PSoC_uGui_Drivers: driver for the ST7735 graphics controller.
* Examples:
	* PSoC4_SPI_SCB: demo/testing project for PSoc 4 microcontroller using a SCB SPI component.
	* PSoC4_SPI_UDB: demo/testing project for PSoc 4 microcontroller using a UDB SPI component.
	* PSoC5LP_uGui: demo/testing project for PSoC 5LP.

Examples for PSoC 4 has been developed using a Cypress development kit CY8CKIT-042 PSoC 4 Pioneer Kit.
Example for PSoC 5LP has been developed using a Cypress development kit CY8CKIT-059.

If you want to try the examples directly connect the display to the board as follows:

| Display       | PSoC 4 board  | PSoC 5LP board| Signal
| ------------- |:-------------:|:-------------:|:--------
| RST           | P0.0          | P0.4          | Display reset
| CS            | P3.4          | P2.0          | SPI SS
| D/C           | P3.7          | P0.5          | Data/Command mode
| DIN           | P3.0          | P12.3         | SPI MOSI
| CLK           | P0.6          | P12.4         | SPI SCLK
| VCC           | 3.3 V         | ext 3.3V	|
| GND           | GND           | GND           |
| BL            | 3.3V          | ext 3.3V	| Back Light

Remember that this kind of displays works at 3.3V.
If you are using a display like mine, probably it has an on board voltage regulator and a jumper you can use to configure the display to work at 5V or 3.3V
Remember to configure your PSoC board accordingly to the voltage of your display and don´t forget, that if you use 5V, you will need some kind of level adapter at digital signals.

![alt tag](https://cloud.githubusercontent.com/assets/15149053/14770137/40f12f88-0a6a-11e6-9399-d25bcceb3137.png)

### Configuration. ###
uGui is configured in "ugui_config.h" file. Follow instructions in the reference guide to configure the uGui library.
To configure the ST7735 driver, read instructions at the top of file "ugui_st7735.h"


### Known issues. ###
Actually i am using PSoC Creator version 3.3 CP2 with ARM GCC 4.9.

I don´t know why, but if i use code optimization during compilation, nothing works. For now, code optimizations have to be deactivated for both "debug" and "release" configurations.
It is something i have to investigate when i have the time to do it.

To deactivate code optimization in PSoC Creator, in left panel (Workspace Explorer), right click the project. Select "build settings" and then in 'ARM GCC 4.9...' -> 'Optimization' -> 'Optimization level', select NONE for "debug" and also for "release".

