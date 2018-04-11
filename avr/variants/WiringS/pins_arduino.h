/*
Arduino variant file for Wiring S

Pin mapping based on: http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/WiringS/BoardInfo.txt?revision=1138
(alternate link: https://github.com/WiringProject/Wiring/blob/master/framework/hardware/Wiring/WiringS/BoardInfo.txt)

Based on the MegaCore:standard variant file created by MCUdude https://github.com/MCUdude/MightyCore/blob/176e9fd5415ed42d533e592b1a88b94a92ee1fdb/avr/variants/standard/pins_arduino.h

                         ATmega644P
                         +---\/---+
            (D 16) PB0  1|        |40  PA0 (A 0 / D24)
            (D 17) PB1  2|        |39  PA1 (A 1 / D25)
       INT2 (D 18) PB2  3|        |38  PA2 (A 2 / D26)
        PWM (D 19) PB3  4|        |37  PA3 (A 3 / D27)
     PWM/SS (D 20) PB4  5|        |36  PA4 (A 4 / D28)
       MOSI (D 21) PB5  6|        |35  PA5 (A 5 / D29)
       MISO (D 22) PB6  7|        |34  PA6 (A 6 / D30)
        SCK (D 23) PB7  8|        |33  PA7 (A 7 / D31)
                   RST  9|        |32  AREF
                   VCC 10|        |31  GND
                   GND 11|        |30  AVCC
                 XTAL2 12|        |29  PC7 (D 15) LED
                 XTAL1 13|        |28  PC6 (D 14)
        RX0 (D 0)  PD0 14|        |27  PC5 (D 13) TDI
        TX0 (D 1)  PD1 15|        |26  PC4 (D 12) TDO
  (RX1)/INT0 (D 2) PD2 16|        |25  PC3 (D 11) TMS
  (TX1)/INT1 (D 3) PD3 17|        |24  PC2 (D 10) TCK
         PWM (D 4) PD4 18|        |23  PC1 (D 9) SDA
         PWM (D 5) PD5 19|        |22  PC0 (D 8) SCL
         PWM (D 6) PD6 20|        |21  PD7 (D 7) PWM
                         +--------+

PCINT15-8: D7-0    : bit 1
PCINT31-24: D15-8  : bit 3
PCINT23-16: D23-16 : bit 2
PCINT7-0: D31-24   : bit 0
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>


#define WIRINGS_PINOUT
#define WIRING_PORTS 4


#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define EXTERNAL_NUM_INTERRUPTS     3
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 24 ? (p) - 24 : -1)
#define digitalPinToInterrupt(p)    ((p) == 2 ? 0 : (p) == 3 ? 1 : (p) == 18 ? 2 : NOT_AN_INTERRUPT)
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 19 || (p) == 20)

#define LED_BUILTIN 15
#define WLED LED_BUILTIN

#define PIN_SPI_SS (20)
#define PIN_SPI_MOSI (21)
#define PIN_SPI_MISO (22)
#define PIN_SPI_SCK (23)

static const uint8_t SS = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

#define PIN_WIRE_SDA (9)
#define PIN_WIRE_SCL (8)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_A0 (24)
#define PIN_A1 (25)
#define PIN_A2 (26)
#define PIN_A3 (27)
#define PIN_A4 (28)
#define PIN_A5 (29)
#define PIN_A6 (30)
#define PIN_A7 (31)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;

#define digitalPinToPCICR(p)    ((p) >= 0 && (p) < NUM_DIGITAL_PINS ? &PCICR : (uint8_t *)0)
#define digitalPinToPCICRbit(p) ((p) <= 7 ? 3 : (p) <= 15 ? 2 : (p) <= 23 ? 1 : 0)
#define digitalPinToPCMSK(p)    ((p) <= 7 ? &PCMSK3 : (p) <= 15 ? &PCMSK2 : (p) <= 23 ? &PCMSK1 : &PCMSK0)
#define digitalPinToPCMSKbit(p) ((p) % 8)



#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

// specify port for each Arduino pin 0-31
#define PORT_D0 PD
#define PORT_D1 PD
#define PORT_D2 PD
#define PORT_D3 PD
#define PORT_D4 PD
#define PORT_D5 PD
#define PORT_D6 PD
#define PORT_D7 PD

#define PORT_D8 PC
#define PORT_D9 PC
#define PORT_D10 PC
#define PORT_D11 PC
#define PORT_D12 PC
#define PORT_D13 PC
#define PORT_D14 PC
#define PORT_D15 PC

#define PORT_D16 PB
#define PORT_D17 PB
#define PORT_D18 PB
#define PORT_D19 PB
#define PORT_D20 PB
#define PORT_D21 PB
#define PORT_D22 PB
#define PORT_D23 PB

#define PORT_D24 PA
#define PORT_D25 PA
#define PORT_D26 PA
#define PORT_D27 PA
#define PORT_D28 PA
#define PORT_D29 PA
#define PORT_D30 PA
#define PORT_D31 PA

// specify port bit for each Arduino pin 0-31
#define BIT_D0 0
#define BIT_D1 1
#define BIT_D2 2
#define BIT_D3 3
#define BIT_D4 4
#define BIT_D5 5
#define BIT_D6 6
#define BIT_D7 7

#define BIT_D8 0
#define BIT_D9 1
#define BIT_D10 2
#define BIT_D11 3
#define BIT_D12 4
#define BIT_D13 5
#define BIT_D14 6
#define BIT_D15 7

#define BIT_D16 0
#define BIT_D17 1
#define BIT_D18 2
#define BIT_D19 3
#define BIT_D20 4
#define BIT_D21 5
#define BIT_D22 6
#define BIT_D23 7

#define BIT_D24 0
#define BIT_D25 1
#define BIT_D26 2
#define BIT_D27 3
#define BIT_D28 4
#define BIT_D29 5
#define BIT_D30 6
#define BIT_D31 7

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[NUM_DIGITAL_PINS] =
{
  PORT_D0,
  PORT_D1,
  PORT_D2,
  PORT_D3,
  PORT_D4,
  PORT_D5,
  PORT_D6,
  PORT_D7,
  PORT_D8,
  PORT_D9,
  PORT_D10,
  PORT_D11,
  PORT_D12,
  PORT_D13,
  PORT_D14,
  PORT_D15,
  PORT_D16,
  PORT_D17,
  PORT_D18,
  PORT_D19,
  PORT_D20,
  PORT_D21,
  PORT_D22,
  PORT_D23,
  PORT_D24,
  PORT_D25,
  PORT_D26,
  PORT_D27,
  PORT_D28,
  PORT_D29,
  PORT_D30,
  PORT_D31
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[NUM_DIGITAL_PINS] =
{
  _BV(BIT_D0),
  _BV(BIT_D1),
  _BV(BIT_D2),
  _BV(BIT_D3),
  _BV(BIT_D4),
  _BV(BIT_D5),
  _BV(BIT_D6),
  _BV(BIT_D7),
  _BV(BIT_D8),
  _BV(BIT_D9),
  _BV(BIT_D10),
  _BV(BIT_D11),
  _BV(BIT_D12),
  _BV(BIT_D13),
  _BV(BIT_D14),
  _BV(BIT_D15),
  _BV(BIT_D16),
  _BV(BIT_D17),
  _BV(BIT_D18),
  _BV(BIT_D19),
  _BV(BIT_D20),
  _BV(BIT_D21),
  _BV(BIT_D22),
  _BV(BIT_D23),
  _BV(BIT_D24),
  _BV(BIT_D25),
  _BV(BIT_D26),
  _BV(BIT_D27),
  _BV(BIT_D28),
  _BV(BIT_D29),
  _BV(BIT_D30),
  _BV(BIT_D31)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  TIMER1B,  //4
  TIMER1A,  //5
  TIMER2B,  //6
  TIMER2A,  //7

  NOT_ON_TIMER, //8
  NOT_ON_TIMER, //9
  NOT_ON_TIMER, //10
  NOT_ON_TIMER, //11
  NOT_ON_TIMER, //12
  NOT_ON_TIMER, //13
  NOT_ON_TIMER, //14
  NOT_ON_TIMER, //15

  NOT_ON_TIMER, //16
  NOT_ON_TIMER, //17
  NOT_ON_TIMER, //18
  TIMER0A,  //19
  TIMER0B,  //20
  NOT_ON_TIMER, //21
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23

  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
  NOT_ON_TIMER, //28
  NOT_ON_TIMER, //29
  NOT_ON_TIMER, //30
  NOT_ON_TIMER  //31
};
#endif  //ARDUINO_MAIN


// Provide a more helpful error message when wirino's LTO option is set to Yes but the installed version of Arduino AVR Boards does not support it
#define WIRINO_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#if defined(WIRINO_COMPILER_LTO) && WIRINO_GCC_VERSION < 40902
#error Your compiler does not support LTO. Please either upgrade Arduino AVR Boards or select Tools > Compiler LTO > No.
#endif  //defined(WIRINO_COMPILER_LTO) && WIRINO_GCC_VERSION < 40902
#undef WIRINO_GCC_VERSION


#endif  //Pins_Arduino_h

// vim:ai:cin:sts=2 sw=2 ft=cpp
