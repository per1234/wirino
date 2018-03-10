/*
Arduino variant file for Wiring S

Pin mapping based on: http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/WiringSPlayShield/BoardDefs.cpp?revision=1229 and http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/WiringSPlayShield/BoardDefs.h?revision=1160
(alternate link: https://github.com/WiringProject/Wiring/blob/master/framework/hardware/Wiring/WiringSPlayShield/BoardDefs.cpp)

Based on the MegaCore:standard variant file created by MCUdude https://github.com/MCUdude/MightyCore/blob/176e9fd5415ed42d533e592b1a88b94a92ee1fdb/avr/variants/standard/pins_arduino.h

                         ATmega644P
                         +---\/---+
            (D 28) PB0  1|        |40  PA0 (A 0 / D14)
            (D 29) PB1  2|        |39  PA1 (A 1 / D15)
        INT2 (D 8) PB2  3|        |38  PA2 (A 2 / D16)
         PWM (D 9) PB3  4|        |37  PA3 (A 3 / D17)
     PWM/SS (D 10) PB4  5|        |36  PA4 (A 4 / D18)
       MOSI (D 11) PB5  6|        |35  PA5 (A 5 / D19)
       MISO (D 12) PB6  7|        |34  PA6 (A 6 / D30)
        SCK (D 13) PB7  8|        |33  PA7 (A 7 / D31)
                   RST  9|        |32  AREF
                   VCC 10|        |31  GND
                   GND 11|        |30  AVCC
                 XTAL2 12|        |29  PC7 (D 25) LED
                 XTAL1 13|        |28  PC6 (D 24)
         RX0 (D 0) PD0 14|        |27  PC5 (D 23) TDI
         TX0 (D 1) PD1 15|        |26  PC4 (D 22) TDO
  (RX1)/INT0 (D 2) PD2 16|        |25  PC3 (D 21) TMS
  (TX1)/INT1 (D 4) PD3 17|        |24  PC2 (D 20) TCK
         PWM (D 3) PD4 18|        |23  PC1 (D 27) SDA
         PWM (D 5) PD5 19|        |22  PC0 (D 26) SCL
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


#define WIRINGSPLAYSHIELD_PINOUT
#define WIRING_PORTS 4


#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define EXTERNAL_NUM_INTERRUPTS     3
#define analogInputToDigitalPin(p)  (((p) <= 5) ? (14 + (p)) : ((p) == 6) ? 30 : ((p) == 7) ? 31 : -1)
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS ? (p) : (((p) >= 14) && ((p) <= 19)) ? ((p) - 14) : ((p) == 30) ? 6 : ((p) == 31) ? 7 : -1)
#define digitalPinToInterrupt(p)    ((p) == 2 ? 0 : (p) == 4 ? 1 : (p) == 8 ? 2 : NOT_AN_INTERRUPT)
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 9 || (p) == 10)

#define LED_BUILTIN 25
#define WLED LED_BUILTIN

#define PIN_SPI_SS (10)
#define PIN_SPI_MOSI (11)
#define PIN_SPI_MISO (12)
#define PIN_SPI_SCK (13)

static const uint8_t SS = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

#define PIN_WIRE_SDA (27)
#define PIN_WIRE_SCL (26)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_A0 (14)
#define PIN_A1 (15)
#define PIN_A2 (16)
#define PIN_A3 (17)
#define PIN_A4 (18)
#define PIN_A5 (19)
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
#define digitalPinToPCICRbit(p) ((p) <= 7 ? 3 : (p) <= 13 ? 1 : (p) <= 19 ? 0 : (p) <= 27 ? 2 : (p) <= 29 ? 1 : 0)
#define digitalPinToPCMSK(p)    ((p) <= 7 ? &PCMSK3 : (p) <= 13 ? &PCMSK1 : (p) <= 19 ? &PCMSK0 : (p) <= 27 ? &PCMSK2 : (p) <= 29 ? &PCMSK1 : &PCMSK0)
#define digitalPinToPCMSKbit(p) ((p) <= 2 ? (p) : (p) == 3 ? 4 : (p) == 4 ? 3 : (p) <= 7 ? (p) : (p) <= 13 ? (p) - 6 : (p) <= 19 ? (p) - 14 : (p) <= 25 ? (p) - 18 : (p) <= 27 ? (p) - 26 : (p) <= 29 ? (p) - 28 : (p) - 24)



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

#define PORT_D8 PB
#define PORT_D9 PB
#define PORT_D10 PB
#define PORT_D11 PB
#define PORT_D12 PB
#define PORT_D13 PB
#define PORT_D14 PA
#define PORT_D15 PA

#define PORT_D16 PA
#define PORT_D17 PA
#define PORT_D18 PA
#define PORT_D19 PA
#define PORT_D20 PC
#define PORT_D21 PC
#define PORT_D22 PC
#define PORT_D23 PC

#define PORT_D24 PC
#define PORT_D25 PC
#define PORT_D26 PC
#define PORT_D27 PC
#define PORT_D28 PB
#define PORT_D29 PB
#define PORT_D30 PA
#define PORT_D31 PA

// specify port bit for each pin D0-D31
#define BIT_D0 0
#define BIT_D1 1
#define BIT_D2 2
#define BIT_D3 4
#define BIT_D4 3
#define BIT_D5 5
#define BIT_D6 6
#define BIT_D7 7

#define BIT_D8 2
#define BIT_D9 3
#define BIT_D10 4
#define BIT_D11 5
#define BIT_D12 6
#define BIT_D13 7
#define BIT_D14 0
#define BIT_D15 1

#define BIT_D16 2
#define BIT_D17 3
#define BIT_D18 4
#define BIT_D19 5
#define BIT_D20 2
#define BIT_D21 3
#define BIT_D22 4
#define BIT_D23 5

#define BIT_D24 6
#define BIT_D25 7
#define BIT_D26 0
#define BIT_D27 1
#define BIT_D28 0
#define BIT_D29 1
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
  TIMER1B,  //3
  NOT_ON_TIMER, //4
  TIMER1A,  //5
  TIMER2B,  //6
  TIMER2A,  //7

  NOT_ON_TIMER, //8
  TIMER0A,  //9
  TIMER0B,  //10
  NOT_ON_TIMER, //11
  NOT_ON_TIMER, //12
  NOT_ON_TIMER, //13
  NOT_ON_TIMER, //14
  NOT_ON_TIMER, //15

  NOT_ON_TIMER, //16
  NOT_ON_TIMER, //17
  NOT_ON_TIMER, //18
  NOT_ON_TIMER, //19
  NOT_ON_TIMER, //20
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
#endif  //Pins_Arduino_h

// vim:ai:cin:sts=2 sw=2 ft=cpp
