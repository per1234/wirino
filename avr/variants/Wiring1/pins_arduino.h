/*
Arduino variant file for Wiring V1.0/Wiring Mini V1.0/Wiring V1.1 ATmega1281 / Wiring V1.1 ATmega2561 boards

Pin mapping from: http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/Wiring1/BoardInfo.txt?revision=1143
(alternate link: https://github.com/WiringProject/Wiring/blob/master/framework/hardware/Wiring/Wiring1/BoardInfo.txt)
and http://wiring.uniandes.edu.co/source/trunk/wiring/firmware/hardware/Wiring/Wiring1.1/BoardInfo.txt?revision=1232
(alternate link: https://github.com/WiringProject/Wiring/blob/master/framework/hardware/Wiring/Wiring1.1/BoardInfo.txt)

Based on the MegaCore:standard variant file created by MCUdude https://github.com/MCUdude/MegaCore/blob/073dd2ead9886a9d93d48538d5bae72e2886f7b4/avr/variants/64-pin-avr/pins_arduino.h

     ARD.  AVR
     PINS  PINS
     |>    |              A0  A1  A2  A3  A4  A5  A6  A7
     |>    |              40  41  42  43  44  45  46  47          16  17  18
     |     | >AVC GND ARE PF0 PF1 PF2 PF3 PF4 PF5 PF6 PF7 GND VCC PA0 PA1 PA2
     V     V   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
     53~* PG5 |                                                             | PA3 19
RX0  32   PE0 |                                                             | PA4 20
TX0  33   PE1 |                                                             | PA5 21
     34   PE2 |                                                             | PA6 22
     35~  PE3 |                                                             | PA7 23
     36~  PE4 |                                                             | PG2 50
     37~  PE5 |                                                             | PC7 15
     38   PE6 |                                                             | PC6 14
     39   PE7 |                                                             | PC5 13
SS   24   PB0 |                                                             | PC4 12
SCK  25   PB1 |                                                             | PC3 11
MOSI 26   PB2 |                                                             | PC2 10
MISO 27   PB3 |                                                             | PC1 9
     28~  PB4 |                                                             | PC0 8
     29~  PB5 |                                                             | PG1 49
     30~  PB6 |                                                             | PG0 48 LED
               -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
              PB7 PG3 PG4 RST VCC GND XT2 XT1 PD0 PD1 PD2 PD3 PD4 PD5 PD6 PD7
              31~ 51  52                       0   1   2   3   4   5   6   7
                                              SCL SDA RX1 TX1

* Arduino pin 53/PG5 on ATmega1281/2561 only. PEN on ATmega128.
~ PWM
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#include <avr/pgmspace.h>


#define WIRING1_PINOUT
#define WIRING_PORTS 7


#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#define NUM_DIGITAL_PINS            53
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define NUM_DIGITAL_PINS            54
#endif  //defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#define NUM_ANALOG_INPUTS           8
#define EXTERNAL_NUM_INTERRUPTS     8
#define analogInputToDigitalPin(p) (((p) < 8) ? ((p) + 40) : -1)
#define analogPinToChannel(p)      ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 40 ? (p) - 40 : -1)
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#define digitalPinHasPWM(p) ((((p) >= 28) && ((p) <= 31)) || (((p) >= 35) && ((p) <= 37)))
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define digitalPinHasPWM(p) ((((p) >= 28) && ((p) <= 31)) || (((p) >= 35) && ((p) <= 37)) || ((p) == 53))
#endif  //defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#define digitalPinToInterrupt(p) ((((p) >= 0) && ((p) <= 3)) ? (p) : (((p) >= 36) && ((p) <= 39)) ? ((p) - 32) : NOT_AN_INTERRUPT)

#define PIN_SPI_SS (24)
#define PIN_SPI_MOSI (25)
#define PIN_SPI_MISO (26)
#define PIN_SPI_SCK (27)

static const uint8_t SS = PIN_SPI_SS;
static const uint8_t SCK = PIN_SPI_MOSI;
static const uint8_t MOSI = PIN_SPI_MISO;
static const uint8_t MISO = PIN_SPI_SCK;

#define LED_BUILTIN 48
#define WLED LED_BUILTIN

#define PIN_WIRE_SDA (1)
#define PIN_WIRE_SCL (0)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_A0 (16)
#define PIN_A1 (17)
#define PIN_A2 (18)
#define PIN_A3 (19)
#define PIN_A4 (20)
#define PIN_A5 (21)
#define PIN_A6 (22)
#define PIN_A7 (23)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;


#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
// PCINT defs
#define digitalPinToPCICR(p) (((((p) >= 24) && ((p) <= 31)) || ((p) == 32)) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) >= 24) && ((p) <= 31)) ? 0 : ((p) == 32) ? 1 : 0)
#define digitalPinToPCMSK(p) ((((p) >= 24) && ((p) <= 31)) ? (&PCMSK0) : ((p) == 32) ? (&PCMSK1) : ((uint8_t *)0))
#define digitalPinToPCMSKbit(p) ((((p) >= 24) && ((p) <= 31)) ? ((p) - 24) : 0)
#endif



#ifdef ARDUINO_MAIN

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

#define PORT_D16 PA
#define PORT_D17 PA
#define PORT_D18 PA
#define PORT_D19 PA
#define PORT_D20 PA
#define PORT_D21 PA
#define PORT_D22 PA
#define PORT_D23 PA

#define PORT_D24 PB
#define PORT_D25 PB
#define PORT_D26 PB
#define PORT_D27 PB
#define PORT_D28 PB
#define PORT_D29 PB
#define PORT_D30 PB
#define PORT_D31 PB

#define PORT_D32 PE
#define PORT_D33 PE
#define PORT_D34 PE
#define PORT_D35 PE
#define PORT_D36 PE
#define PORT_D37 PE
#define PORT_D38 PE
#define PORT_D39 PE

#define PORT_D40 PF
#define PORT_D41 PF
#define PORT_D42 PF
#define PORT_D43 PF
#define PORT_D44 PF
#define PORT_D45 PF
#define PORT_D46 PF
#define PORT_D47 PF

#define PORT_D48 PG
#define PORT_D49 PG
#define PORT_D50 PG
#define PORT_D51 PG
#define PORT_D52 PG
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define PORT_D53 PG
#endif  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)



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

#define BIT_D32 0
#define BIT_D33 1
#define BIT_D34 2
#define BIT_D35 3
#define BIT_D36 4
#define BIT_D37 5
#define BIT_D38 6
#define BIT_D39 7

#define BIT_D40 0
#define BIT_D41 1
#define BIT_D42 2
#define BIT_D43 3
#define BIT_D44 4
#define BIT_D45 5
#define BIT_D46 6
#define BIT_D47 7

#define BIT_D48 0
#define BIT_D49 1
#define BIT_D50 2
#define BIT_D51 3
#define BIT_D52 4
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define BIT_D53 5
#endif  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)

const uint16_t PROGMEM port_to_mode_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
  (uint16_t) &DDRE,
  (uint16_t) &DDRF,
  (uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
  (uint16_t) &PORTE,
  (uint16_t) &PORTF,
  (uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
  NOT_A_PIN,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
  (uint16_t) &PINE,
  (uint16_t) &PINF,
  (uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
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
  PORT_D31,
  PORT_D32,
  PORT_D33,
  PORT_D34,
  PORT_D35,
  PORT_D36,
  PORT_D37,
  PORT_D38,
  PORT_D39,
  PORT_D40,
  PORT_D41,
  PORT_D42,
  PORT_D43,
  PORT_D44,
  PORT_D45,
  PORT_D46,
  PORT_D47,
  PORT_D48,
  PORT_D49,
  PORT_D50,
  PORT_D51,
  PORT_D52,
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  PORT_D53,
#endif  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
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
  _BV(BIT_D31),
  _BV(BIT_D32),
  _BV(BIT_D33),
  _BV(BIT_D34),
  _BV(BIT_D35),
  _BV(BIT_D36),
  _BV(BIT_D37),
  _BV(BIT_D38),
  _BV(BIT_D39),
  _BV(BIT_D40),
  _BV(BIT_D41),
  _BV(BIT_D42),
  _BV(BIT_D43),
  _BV(BIT_D44),
  _BV(BIT_D45),
  _BV(BIT_D46),
  _BV(BIT_D47),
  _BV(BIT_D48),
  _BV(BIT_D49),
  _BV(BIT_D50),
  _BV(BIT_D51),
  _BV(BIT_D52),
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  _BV(BIT_D53),
#endif  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, //0
  NOT_ON_TIMER, //1
  NOT_ON_TIMER, //2
  NOT_ON_TIMER, //3
  NOT_ON_TIMER, //4
  NOT_ON_TIMER, //5
  NOT_ON_TIMER, //6
  NOT_ON_TIMER, //7

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
  NOT_ON_TIMER, //19
  NOT_ON_TIMER, //20
  NOT_ON_TIMER, //21
  NOT_ON_TIMER, //22
  NOT_ON_TIMER, //23

  NOT_ON_TIMER, //24
  NOT_ON_TIMER, //25
  NOT_ON_TIMER, //26
  NOT_ON_TIMER, //27
#if defined(__AVR_ATmega128__)
  TIMER0, //28
#else //defined(__AVR_ATmega128__)
  TIMER2A,  //28
#endif  //defined(__AVR_ATmega128__)
  TIMER1A,  //29
  TIMER1B,  //30
  TIMER1C,  //31

  NOT_ON_TIMER, //32
  NOT_ON_TIMER, //33
  NOT_ON_TIMER, //34
  TIMER3A,  //35
  TIMER3B,  //36
  TIMER3C,  //37
  NOT_ON_TIMER, //38
  NOT_ON_TIMER, //39

  NOT_ON_TIMER, //40
  NOT_ON_TIMER, //41
  NOT_ON_TIMER, //42
  NOT_ON_TIMER, //43
  NOT_ON_TIMER, //44
  NOT_ON_TIMER, //45
  NOT_ON_TIMER, //46
  NOT_ON_TIMER, //47

  NOT_ON_TIMER, //48
  NOT_ON_TIMER, //49
  NOT_ON_TIMER, //50
  NOT_ON_TIMER, //51
  NOT_ON_TIMER, //52
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  TIMER0B, //53
#endif  //defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
};

#endif  //ARDUINO_MAIN
#endif  //Pins_Arduino_h
