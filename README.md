<img src="wirino.svg" alt="logo" height="85" align="right" />

wirino
==========
Use your Wiring boards with the [Arduino](http://arduino.cc) IDE

The [Wiring](http://wiring.org.co/) project was initiated in 2003 by Hernando Barragán. In 2005 Wiring was used as the starting point and inspiration for the creation of Arduino. The Wiring IDE is no longer under active development and the Wiring boards are no longer in production, though the Wiring S is [still available for purchase](https://roguerobotics.com/collections/roguerobotics/products/wiring-s). For more Wiring history see https://arduinohistory.github.io.

In addition to the Wiring boards hardware definitions, this package provides [advanced configuration options](#usage). The [referenced core](#required-cores) libraries also provide [Wiring API functions](https://github.com/MCUdude/MightyCore/blob/master/Wiring_reference.md).


## Supported Boards
- Wiring S
- Wiring S with Play Shield
- Wiring V1.0
- Wiring Mini V1.0
- Wiring V1.1 ATmega1281
- Wiring V1.1 ATmega2561


## Installation
There are two options for installing **wirino** in the Arduino IDE:
#### Boards Manager Installation(requires Arduino IDE version 1.6.4 or greater)
- Open the Arduino IDE.
- Open the **File > Preferences** menu item.
- Enter the following URL in **Additional Boards Manager URLs**:
https://per1234.github.io/wirino/package_per1234_wirino_index.json
- Open the **Tools > Board > Boards Manager...** menu item.
- Wait for the platform indexes to finish downloading.
- Scroll down until you see the **wirino** entry and click on it.
- Click **Install**.
- After installation is complete close the **Boards Manager** window.

#### Manual Installation(requires Arduino IDE version 1.6.1 or greater)
- Download wirino
  - Stable releases: https://github.com/per1234/wirino/releases
  - Beta test version: https://github.com/per1234/wirino/archive/master.zip
- Extract the downloaded file.
- rename the extracted folder **wirino**.
- Move the **wirino** folder into the **hardware** subfolder of your sketchbook folder. You can find the location of your sketchbook folder in the Arduino IDE at **File > Preferences > Sketchbook location:**.
- If the Arduino IDE is running then restart it.


#### Required Cores
**wirino** only provides hardware definitions and bootloader files. You also need to install the core files to support your Wiring board. Follow the installation instructions found on the core's page.
- Wiring S, Wiring S with Play Shield - [MightyCore](https://github.com/MCUdude/MightyCore)
- Wiring V1.1, Wiring V1.0 - [MegaCore](https://github.com/MCUdude/MegaCore)


## Usage
After installing wirino several new boards are added to the **wirino** section of the **Tools > Board** menu. When any of these boards are selected additional menus will appear under the **Tools** menu.

Whenever you change a setting in any of these menus other than **Compiler LTO** you need to do a **Tools > Burn Bootloader** to reconfigure your board.

#### BOD Menu
BOD stands for Brown-out Detection. This feature is intended to avoid improper operation caused by insufficient supply voltage. If the supply voltage drops below the BOD value then the microcontroller is reset.

#### Clock Menu
- **16MHz** - This is the default clock speed of the Wiring boards.
- **8MHz Internal** - May be used to reduce power consumption.

#### Bootloader Menu
- **Wiring** - The bootloaders included with the Wiring IDE v1.0 build 0101.
- **Optiboot** - This is a more modern bootloader which will free up 1 kB of flash memory. This is actually a [special variant of Optiboot](https://github.com/MCUdude/optiboot_flash) which allows writing to flash from the application. See **File > Examples > Optiboot flash read/write > SerialReadWrite**.
- **None** - If you use an ISP(in-system programmer) to upload sketches to your Wiring board with this option selected you will be able to use the full flash memory capacity of the microcontroller.

#### Preserve EEPROM
- **Yes** - The contents of the EEPROM will be preserved through **Tools > Burn Bootloader** and **Sketch > Upload Using Programmer**.
- **No** - The contents of the EEPROM will not be preserved through **Tools > Burn Bootloader** and **Sketch > Upload Using Programmer**.

#### Compiler LTO
Link Time Optimization (LTO) is a compiler optimization that can significantly reduce memory usage of your sketch. It requires Arduino AVR Boards 1.6.12 or newer to be installed.


## Troubleshooting
- **wirino** entry doesn't appear in Boards Manager when using Arduino IDE 1.6.6.
  - Close Boards Manager and then open it again.
- wirino boards don't appear in the **Tools > Board** menu after manual installation.
  - wirino requires Arduino IDE 1.6.1 or higher.
- `The current selected board needs the core 'MegaCore:MCUdude_corefiles/MightyCore/MightyCore' that is not installed.` or `Selected board depends on 'MegaCore/MightyCore' core (not installed).` or `fatal error: Arduino.h: No such file or directory`
  - You must [install the required core](#required-cores).
- `cc1.exe: error: -fno-fat-lto-objects are supported only with linker plugin.`
  - You have [**Tools > Compiler LTO**](#compiler-lto) set to **Yes** but have a version of Arduino AVR Boards installed that doesn't support LTO. Either update to a newer version of Arduino AVR Boards or select **Tools > Compiler LTO > No**.
- `Bootloader file specified but missing` warning while compiling when using Arduino IDE 1.6.6.
  - Please ignore, this is caused by a bug in that IDE version and will not cause any problems.
- A library or sketch doesn't work correctly with wirino.
  - The microcontroller models used on the Wiring boards are different from those used on the Arduino boards. Many libraries and example sketches will work fine on Wiring boards, however the authors of some Arduino libraries or example sketches have only written their hardware specific code to work with the microcontrollers used on standard Arduino boards. MightyCore contains a collection of libraries modified to work with Wiring S and Wiring Play Shield boards. MegaCore contains libraries modified to work with Wiring V1.1 and Wiring V1.0 boards. You can easily modify other libraries/code to support your microcontroller, see https://github.com/MCUdude/MightyCore/blob/master/Library_porting.md for instructions.
- `avrdude: verification error; content mismatch` error during lock verification while burning bootloader with AVRISP mkII or other STK500v2 programmer.
  - wirino is not compatible with Arduino AVR Boards 1.6.12 (included with Arduino IDE 1.6.10). Please use any other version of Arduino AVR Boards.
- `avrdude: AVR Part "build.mcu" not found.` or `avr-g++: error: unrecognized argument in option '-mmcu=build.mcu'`.
  - wirino requires Arduino IDE 1.6.1 or greater,
- Uploading fails after configuring the board to run at 8 MHz.
  - The internal oscillator used for the 8 MHz clock is not as accurate as the external 16 MHz clock source on your board. In some cases it might be so far off as to not allow uploads. Use the 16 MHz clock speed instead.
- I found a bug.
  - Please read the [Contribution Rules](https://github.com/per1234/wirino/blob/master/CONTRIBUTING.md) for instructions on reporting it.


## Contributing
Pull requests or issue reports are welcome! Please see the [contribution rules](https://github.com/per1234/wirino/blob/master/CONTRIBUTING.md) for instructions.


## Acknowledgments
- [Hernando Barragán](http://wiring.org.co) - Founder of Wiring.
- [MCUdude](https://github.com/MCUdude)
  - [MightyCore](https://github.com/MCUdude/MightyCore)
  - [MegaCore](https://github.com/MCUdude/MegaCore)
  - [MightyCore:standard](https://github.com/MCUdude/MightyCore/blob/master/avr/variants/standard/pins_arduino.h) variant used as a base for the Wiring S and Wiring Play Shield variant files.
  - [MegaCore:64-pin-avr](https://github.com/MCUdude/MegaCore/blob/master/avr/variants/64-pin-avr/pins_arduino.h) variant used as a base for the Wiring 1.0 and Wiring 1.1 variant file.
  - [Modifications to Optiboot](https://github.com/MCUdude/optiboot_flash) source code to support the ATmega128.
- [majekw](https://github.com/majekw) - [Modifications to Optiboot](https://github.com/majekw/optiboot) to support microcontrollers with larger flash sizes and writing to flash from the application.


## Wiring Theme
If you like Wiring and Arduino you might be interested in a theme for the Arduino IDE that will make it look like the Wiring IDE:
https://github.com/per1234/ino-themes/tree/Wiring-theme
