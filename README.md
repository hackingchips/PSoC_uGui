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

Examples for PSoC 4 have been developed using a Cypress development kit CY8CKIT-042 PSoC 4 Pioneer Kit. If you want to try the examples directly connect the display to the board as follows:

| Display       | PSoC 4 board  | Signal
| ------------- |:-------------:|:--------
| RST           | P0.0          | Display reset
| CS            | P3.4          | SPI SS
| D/C           | P3.7          | Data/Command mode
| DIN           | P3.0          | SPI MOSI
| CLK           | P0.6          | SPI SCLK
| VCC           | 3.3 V         |
| GND           | GND           |
| BL            | 3.3V          | Back Light

Remember that this kind of displays works at 3.3V.
If you are using a display like mine, probably it have an on board voltage regulator and a jumper you can use to configure the display to work at 5V or 3.3V
Remember to configure your PSoC board accordingly to the voltage of your display and don´t forget, that if you use 5V, you will need some kind of level adapter at digital signals.

https://cloud.githubusercontent.com/assets/15149053/14770137/40f12f88-0a6a-11e6-9399-d25bcceb3137.png



### Known issues. ###
Actually i am using PSoC Creator version 3.3 CP2 with ARM GCC 4.9.

I don´t know why, but if i use code optimization during compilation, nothing works. For now, code optimizations have to be deactivated for both "debug" and "release" configurations.
It is something i have to investigate when i have the time to do it.

To deactivate code optimization in PSoC Creator, in left panel (Workspace Explorer), right click the project. Select "build settings" and then in 'ARM GCC 4.9...' -> 'Optimization' -> 'Optimization level', select NONE for "debug" and also for "release".

