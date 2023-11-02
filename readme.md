# readme

# Tavern64

*A versatile 65-ish percent keyboard where (almost) everything is optional.*

## Features

- MX, Choc V1 & V2 switch support with multiple options:
    1. MX *AND* Choc hot-swap sockets, *NO* per-key RGB
    2. MX hot-swap sockets, *NO* per-key RGB
    3. Choc hot-swap sockets, *NO* per-key RGB
    4. MX hot-swap sockets *AND* per-key RGB
    5. Choc hot-swap sockets *AND* per-key RGB
- Split spacebar layouts:
    1. Full size (6.25u)
    2. Split A (2.25u, 1.25u, 2.75u)
    3. Split B(2u, 2u, 2u)
- Encoders*
- OLED screen*
- Audio buzzer* with volume control*
- RGB Matrix*
- RGB Under glow*
- Indicator LEDs*
    - Caps Lock, Num Lock, Scroll Lock
- Gasket or case mountable
- Surface-mount or through-hole components:
    - Diodes
    - Resistors
    - Buzzer

*: *optional feature*

## Hardware required

| Description | Part Name | Max # Needed | URL |
| --- | --- | --- | --- |
| Hot-swap sockets | MX hot-swap socket OR Choc Hot-swap socket | 67 |  |
| RGB LED mini | SK6812 mini-e | 65 |  |
| RGB Strip | WS2812B | 1m |  |
| Diodes | 1N4148 | 67 |  |
| Resistor A | 100R | 1 |  |
| Resistor B | 220R | 1 |  |
| Volume Switch | SP3T / 1P3T Switch, 6mm | 1 |  |
| Pin Headers |  | 40 |  |
| Microcontroller | RP2040 Pi Pico (purple) | 1 |  |
| Buzzer | 8530 Passive | 1 |  |
| Encoder | EC11 | 3 |  |
| Large LED | 5mm LED | 1 |  |
| Medium LED | 3mm LED | 3 |  |
| OLED Screen | 0.96” 128x64 I2C OLED, OR 0.91” 128x32 I2C OLED | 1 |  |
| Reset Switch* |  | 1 |  |
| Case Screws | M2 6mm Button Head Hex | 10 |  |
| OLED Screws | M2 4mm Button Head Philips | 2 |  |
| OLED Standoffs | M2 6mm Standoffs | 2 |  |
| Gaskets | PORON Foam 2mm | 6 |  |

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
- **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
