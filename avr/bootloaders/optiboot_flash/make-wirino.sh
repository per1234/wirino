# Script used to compile optiboot_flash for the wirino boards
make clean

make atmega644p AVR_FREQ=16000000L BAUD_RATE=115200 UART=0 LED=C7 LED_START_FLASHES=0 -BIGBOOT
make atmega644p AVR_FREQ=8000000L BAUD_RATE=57600 UART=0 LED=C7 LED_START_FLASHES=0 -BIGBOOT
make atmega1281 AVR_FREQ=16000000L BAUD_RATE=115200 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT
make atmega1281 AVR_FREQ=8000000L BAUD_RATE=57600 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT
make atmega2561 AVR_FREQ=16000000L BAUD_RATE=115200 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT
make atmega2561 AVR_FREQ=8000000L BAUD_RATE=57600 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT
make atmega128 AVR_FREQ=16000000L BAUD_RATE=115200 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT
make atmega128 AVR_FREQ=8000000L BAUD_RATE=57600 UART=0 LED=G0 LED_START_FLASHES=0 -BIGBOOT

# Delete up unnecessary files generated during the compilations
rm --force **/*.lst
rm --force baudcheck.tmp.sh

# Pause so that the output may be examined before script window is exited
read -rsp $'\n\nFinished compiling bootloaders. Press any key to continue...\n' -n 1
