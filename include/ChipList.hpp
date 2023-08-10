/**
 * @file ChipList.hpp
 * @author Sam4uk (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef CHIP_LIST_HPP
#define CHIP_LIST_HPP
#include <string>
const struct AVR_chips {
  std::string       //
      ShortName,    ///<
      FullName;     ///<
  uint16_t          //
      E2PROM_size;  ///<
} E2PROM_list[] {
#if 0
    {"uc3a0512", "AT32UC3A0512", 0x00},    ///< AT32UC3A0512
    {"c128", "AT90CAN128", 0x00},          ///< AT90CAN128
    {"c32", "AT90CAN32", 0x00},            ///< AT90CAN32
    {"c64", "AT90CAN64", 0x00},            ///< AT90CAN64
    {"pwm2", "AT90PWM2", 0x1FF},            ///< AT90PWM2
    {"pwm216", "AT90PWM216", 0x1FF},        ///< AT90PWM216
    {"pwm2b", "AT90PWM2B", 0x1FF},          ///< AT90PWM2B
    {"pwm3", "AT90PWM3", 0x1FF},            ///< AT90PWM3
    {"pwm316", "AT90PWM316", 0x1FF},        ///< AT90PWM316
    {"pwm3b", "AT90PWM3B", 0x1FF},          ///< AT90PWM3B
#endif
  {"1200", "AT90S1200", 0x3F},       ///< AT90S1200
      {"2313", "AT90S2313", 0x7F},   ///< AT90S2313
      {"2333", "AT90S2333", 0x7F},   ///< AT90S2333
      {"2343", "AT90S2343", 0x7F},   ///< AT90S2343
      {"4414", "AT90S4414", 0xFF},   ///< AT90S4414
      {"4433", "AT90S4433", 0xFF},   ///< AT90S4433
      {"4434", "AT90S4434", 0xFF},   ///< AT90S4434
      {"8515", "AT90S8515", 0x1FF},  ///< AT90S8515
      {"8535", "AT90S8535", 0x1FF},  ///< AT90S8535
#if 0
    {"usb1286", "AT90USB1286", 0x00},      ///< AT90USB1286
    {"usb1287", "AT90USB1287", 0x00},      ///< AT90USB1287
    {"usb162", "AT90USB162", 0x00},        ///< AT90USB162
    {"usb646", "AT90USB646", 0x00},        ///< AT90USB646
    {"usb647", "AT90USB647", 0x00},        ///< AT90USB647
    {"usb82", "AT90USB82", 0x00},          ///< AT90USB82
    {"m103", "ATmega103", 0x00},           ///< ATmega103
    {"m128", "ATmega128", 0x00},           ///< ATmega128
    {"m1280", "ATmega1280", 0x00},         ///< ATmega1280
    {"m1281", "ATmega1281", 0x00},         ///< ATmega1281
    {"m1284", "ATmega1284", 0x00},         ///< ATmega1284
    {"m1284p", "ATmega1284P", 0x00},       ///< ATmega1284P
    {"m1284rfr2", "ATmega1284RFR2", 0x00}, ///< ATmega1284RFR2
    {"m128rfa1", "ATmega128RFA1", 0x00},   ///< ATmega128RFA1
    {"m128rfr2", "ATmega128RFR2", 0x00},   ///< ATmega128RFR2
    {"m16", "ATmega16", 0x1FF},             ///< ATmega16
    {"m161", "ATmega161", 0x00},           ///< ATmega161
    {"m162", "ATmega162", 0x00},           ///< ATmega162
    {"m163", "ATmega163", 0x00},           ///< ATmega163
    {"m164p", "ATmega164P", 0x00},         ///< ATmega164P
    {"m168", "ATmega168", 0x00},           ///< ATmega168
    {"m168p", "ATmega168P", 0x00},         ///< ATmega168P
    {"m168pb", "ATmega168PB", 0x00},       ///< ATmega168PB
    {"m169", "ATmega169", 0x00},           ///< ATmega169
    {"m16u2", "ATmega16U2", 0x00},         ///< ATmega16U2
#endif
      {"m2560", "ATmega2560", 0xFFF},  ///< ATmega2560
      {"m2561", "ATmega2561", 0xFFF},  ///< ATmega2561
#if 0
    {"m2564rfr2", "ATmega2564RFR2", 0x00}, ///< ATmega2564RFR2
    {"m256rfr2", "ATmega256RFR2", 0x00},   ///< ATmega256RFR2
    {"m32", "ATmega32", 0x00},             ///< ATmega32
    {"m3208", "ATmega3208", 0x00},         ///< ATmega3208
    {"m3209", "ATmega3209", 0x00},         ///< ATmega3209
    {"m324p", "ATmega324P", 0x00},         ///< ATmega324P
    {"m324pa", "ATmega324PA", 0x00},       ///< ATmega324PA
    {"m325", "ATmega325", 0x00},           ///< ATmega325
    {"m3250", "ATmega3250", 0x00},         ///< ATmega3250
    {"m328", "ATmega328", 0x00},           ///< ATmega328
    {"m328p", "ATmega328P", 0x00},         ///< ATmega328P
    {"m328pb", "ATmega328PB", 0x00},       ///< ATmega328PB
    {"m329", "ATmega329", 0x00},           ///< ATmega329
    {"m3290", "ATmega3290", 0x00},         ///< ATmega3290
    {"m3290p", "ATmega3290P", 0x00},       ///< ATmega3290P
    {"m329p", "ATmega329P", 0x00},         ///< ATmega329P
    {"m32m1", "ATmega32M1", 0x00},         ///< ATmega32M1
    {"m32u2", "ATmega32U2", 0x00},         ///< ATmega32U2
    {"m32u4", "ATmega32U4", 0x00},         ///< ATmega32U4
    {"m406", "ATMEGA406", 0x00},           ///< ATMEGA406
    {"m48", "ATmega48", 0x00},             ///< ATmega48
    {"m4808", "ATmega4808", 0x00},         ///< ATmega4808
    {"m4809", "ATmega4809", 0x00},         ///< ATmega4809
    {"m48p", "ATmega48P", 0x00},           ///< ATmega48P
    {"m48pb", "ATmega48PB", 0x00},         ///< ATmega48PB
    {"m64", "ATmega64", 0x00},             ///< ATmega64
    {"m640", "ATmega640", 0x00},           ///< ATmega640
    {"m644", "ATmega644", 0x00},           ///< ATmega644
    {"m644p", "ATmega644P", 0x00},         ///< ATmega644P
    {"m644rfr2", "ATmega644RFR2", 0x00},   ///< ATmega644RFR2
    {"m645", "ATmega645", 0x00},           ///< ATmega645
    {"m6450", "ATmega6450", 0x00},         ///< ATmega6450
    {"m649", "ATmega649", 0x00},           ///< ATmega649
    {"m6490", "ATmega6490", 0x00},         ///< ATmega6490
    {"m64m1", "ATmega64M1", 0x00},         ///< ATmega64M1
    {"m64rfr2", "ATmega64RFR2", 0x00},     ///< ATmega64RFR2
    {"m8", "ATmega8", 0x00},               ///< ATmega8
    {"m8515", "ATmega8515", 0x00},         ///< ATmega8515
    {"m8535", "ATmega8535", 0x00},         ///< ATmega8535
    {"m88", "ATmega88", 0x00},             ///< ATmega88
    {"m88p", "ATmega88P", 0x00},           ///< ATmega88P
    {"m88pb", "ATmega88PB", 0x00},         ///< ATmega88PB
    {"m8u2", "ATmega8U2", 0x00},           ///< ATmega8U2
    {"t10", "ATtiny10", 0x00},             ///< ATtiny10
    {"t11", "ATtiny11", 0x00},             ///< ATtiny11
    {"t12", "ATtiny12", 0x00},             ///< ATtiny12
    {"t13", "ATtiny13", 0x00},             ///< ATtiny13
    {"t15", "ATtiny15", 0x00},             ///< ATtiny15
    {"t1604", "ATtiny1604", 0x00},         ///< ATtiny1604
    {"t1606", "ATtiny1606", 0x00},         ///< ATtiny1606
    {"t1607", "ATtiny1607", 0x00},         ///< ATtiny1607
    {"t1614", "ATtiny1614", 0x00},         ///< ATtiny1614
    {"t1616", "ATtiny1616", 0x00},         ///< ATtiny1616
    {"t1617", "ATtiny1617", 0x00},         ///< ATtiny1617
    {"t1634", "ATtiny1634", 0x00},         ///< ATtiny1634
    {"t20", "ATtiny20", 0x00},             ///< ATtiny20
    {"t202", "ATtiny202", 0x00},           ///< ATtiny202
    {"t204", "ATtiny204", 0x00},           ///< ATtiny204
    {"t212", "ATtiny212", 0x00},           ///< ATtiny212
    {"t214", "ATtiny214", 0x00},           ///< ATtiny214
    {"t2313", "ATtiny2313", 0x00},         ///< ATtiny2313
    {"t24", "ATtiny24", 0x00},             ///< ATtiny24
    {"t25", "ATtiny25", 0x00},             ///< ATtiny25
    {"t26", "ATtiny26", 0x00},             ///< ATtiny26
    {"t261", "ATtiny261", 0x00},           ///< ATtiny261
    {"t28", "ATtiny28", 0x00},             ///< ATtiny28
    {"t3214", "ATtiny3214", 0x00},         ///< ATtiny3214
    {"t3216", "ATtiny3216", 0x00},         ///< ATtiny3216
    {"t3217", "ATtiny3217", 0x00},         ///< ATtiny3217
    {"t4", "ATtiny4", 0x00},               ///< ATtiny4
    {"t40", "ATtiny40", 0x00},             ///< ATtiny40
    {"t402", "ATtiny402", 0x00},           ///< ATtiny402
    {"t404", "ATtiny404", 0x00},           ///< ATtiny404
    {"t406", "ATtiny406", 0x00},           ///< ATtiny406
    {"t412", "ATtiny412", 0x00},           ///< ATtiny412
    {"t414", "ATtiny414", 0x00},           ///< ATtiny414
    {"t416", "ATtiny416", 0x00},           ///< ATtiny416
    {"t417", "ATtiny417", 0x00},           ///< ATtiny417
    {"t4313", "ATtiny4313", 0x00},         ///< ATtiny4313
    // {"t43u", "ATtiny43u", 0x00},           ///< ATtiny43u
    {"t44", "ATtiny44", 0x00},             ///< ATtiny44
    {"t441", "ATtiny441", 0x00},           ///< ATtiny441
    {"t45", "ATtiny45", 0x00},             ///< ATtiny45
    {"t461", "ATtiny461", 0x00},           ///< ATtiny461
    {"t5", "ATtiny5", 0x00},               ///< ATtiny5
    {"t804", "ATtiny804", 0x00},           ///< ATtiny804
    {"t806", "ATtiny806", 0x00},           ///< ATtiny806
    {"t807", "ATtiny807", 0x00},           ///< ATtiny807
    {"t814", "ATtiny814", 0x00},           ///< ATtiny814
    {"t816", "ATtiny816", 0x00},           ///< ATtiny816
    {"t817", "ATtiny817", 0x00},           ///< ATtiny817
    {"t84", "ATtiny84", 0x00},             ///< ATtiny84
    {"t841", "ATtiny841", 0x00},           ///< ATtiny841
    {"t85", "ATtiny85", 0x00},             ///< ATtiny85
    {"t861", "ATtiny861", 0x7F},           ///< ATtiny861
    {"t88", "ATtiny88", 0x00},             ///< ATtiny88
    {"t9", "ATtiny9", 0x00},               ///< ATtiny9
    {"x128a1", "ATxmega128A1", 0x00},      ///< ATxmega128A1
    {"x128a1d", "ATxmega128A1revD", 0x00}, ///< ATxmega128A1revD
    {"x128a1u", "ATxmega128A1U", 0x00},    ///< ATxmega128A1U
    {"x128a3", "ATxmega128A3", 0x00},      ///< ATxmega128A3
    {"x128a3u", "ATxmega128A3U", 0x00},    ///< ATxmega128A3U
    {"x128a4", "ATxmega128A4", 0x00},      ///< ATxmega128A4
    {"x128a4u", "ATxmega128A4U", 0x00},    ///< ATxmega128A4U
    {"x128b1", "ATxmega128B1", 0x00},      ///< ATxmega128B1
    {"x128b3", "ATxmega128B3", 0x00},      ///< ATxmega128B3
    {"x128c3", "ATxmega128C3", 0x00},      ///< ATxmega128C3
    {"x128d3", "ATxmega128D3", 0x00},      ///< ATxmega128D3
    {"x128d4", "ATxmega128D4", 0x00},      ///< ATxmega128D4
    {"x16a4", "ATxmega16A4", 0x00},        ///< ATxmega16A4
    {"x16a4u", "ATxmega16A4U", 0x00},      ///< ATxmega16A4U
    {"x16c4", "ATxmega16C4", 0x00},        ///< ATxmega16C4
    {"x16d4", "ATxmega16D4", 0x00},        ///< ATxmega16D4
    {"x16e5", "ATxmega16E5", 0x00},        ///< ATxmega16E5
    {"x192a1", "ATxmega192A1", 0x00},      ///< ATxmega192A1
    {"x192a3", "ATxmega192A3", 0x00},      ///< ATxmega192A3
    {"x192a3u", "ATxmega192A3U", 0x00},    ///< ATxmega192A3U
    {"x192c3", "ATxmega192C3", 0x00},      ///< ATxmega192C3
    {"x192d3", "ATxmega192D3", 0x00},      ///< ATxmega192D3
    {"x256a1", "ATxmega256A1", 0x00},      ///< ATxmega256A1
    {"x256a3", "ATxmega256A3", 0x00},      ///< ATxmega256A3
    {"x256a3b", "ATxmega256A3B", 0x00},    ///< ATxmega256A3B
    {"x256a3bu", "ATxmega256A3BU", 0x00},  ///< ATxmega256A3BU
    {"x256a3u", "ATxmega256A3U", 0x00},    ///< ATxmega256A3U
    {"x256c3", "ATxmega256C3", 0x00},      ///< ATxmega256C3
    {"x256d3", "ATxmega256D3", 0x00},      ///< ATxmega256D3
    {"x32a4", "ATxmega32A4", 0x00},        ///< ATxmega32A4
    {"x32a4u", "ATxmega32A4U", 0x00},      ///< ATxmega32A4U
    {"x32c4", "ATxmega32C4", 0x00},        ///< ATxmega32C4
    {"x32d4", "ATxmega32D4", 0x00},        ///< ATxmega32D4
    {"x32e5", "ATxmega32E5", 0x00},        ///< ATxmega32E5
    {"x384c3", "ATxmega384C3", 0x00},      ///< ATxmega384C3
    {"x384d3", "ATxmega384D3", 4096U},      ///< ATxmega384D3
    {"x64a1", "ATxmega64A1", 0x00},        ///< ATxmega64A1
    {"x64a1u", "ATxmega64A1U", 0x00},      ///< ATxmega64A1U
    {"x64a3", "ATxmega64A3", 0x00},        ///< ATxmega64A3
    {"x64a3u", "ATxmega64A3U", 0x00},      ///< ATxmega64A3U
    {"x64a4", "ATxmega64A4", 0x00},        ///< ATxmega64A4
    {"x64a4u", "ATxmega64A4U", 0x00},      ///< ATxmega64A4U
    {"x64b1", "ATxmega64B1", 0x00},        ///< ATxmega64B1
    {"x64b3", "ATxmega64B3", 0x00},        ///< ATxmega64B3
    {"x64c3", "ATxmega64C3", 0x00},        ///< ATxmega64C3
    {"x64d3", "ATxmega64D3", 0x00},        ///< ATxmega64D3
    {"x64d4", "ATxmega64D4", 0x00},        ///< ATxmega64D4
#endif
      {"x8e5", "ATxmega8E5", 0x00},  ///< ATxmega8E5
};

#endif