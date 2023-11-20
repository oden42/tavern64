# Build Guide

**Contents**
- [Before you build](#before-you-build)
	- [Profile type](#a1)
	- [Lighting](#a2)
	- [Encoders & Macro buttons](#a3)
	- [Space bar](#a4)
	- [OLED display](#a5)
	- [Buzzer/Speaker](#a6)
	- [Power](#a7)
	- [Customization!](#a8)
 
- [Instructions](#instructions)
	- [Jumpers](#b1)
		- Step 1: [Solder JP1](#c1)
		- Step 2: [Solder JP2](#c2)
	- [Switches](#b2)
	  	- Step 3: [Hot swap sockets](#c3)
		- Step 4: [Diodes](#c4)
		- Step 5: [Per-Key LEDs](#c5)
	- [Microcontroller](#b3)
		- Step 6: [Solder pin headers](#c6)
		- Step 7: [Solder MCU pins](#c7)
	- [Speaker](#b4)
	  	- Step 8: [Solder volume switch](#c8)
		- Step 9: [Solder resistors](#c9)
		- Step 10: [Solder buzzer](#c10)
	- [OLED Screen](#b5)
	  	- Step 11: [Solder OLED screen](#c11)
	- [Other Features](#b6)
	  	- Step 12: [Solder indicator LEDs](#c12)
		- Step 13: [Solder encoders](#c13)
		- Step 14: [Solder LED strip](#c14)

<a id="before-you-build"></a>
# Before you build

Before you begin building your Tavern64, you’ll need to choose which components to implement. The board was designed to support a variety of features, several of which are optional.

If you already know what you’re building, [skip to the instructions here](#instructions).

<a id="a1"></a>
## Profile type

***Do you want a normal or low profile keyboard?***

The Tavern64 PCB is designed for two different profile types; MX and low profiles (Choc V2). This will affect the overall thickness of the assembled keyboard, and can determine which side of the PCB to mount the RP2040 microcontroller.

*Note: I have built both types of boards, but highly recommend the MX version. I could not find compatible stabilizers to use for low profile board and therefor don’t recommend building one. If you manage to figure that part out, let me know! I could probably make some if I had a good resin 3D printer.*

<a id="a2"></a>
## Lighting

***How do you want your keyboard to light up?***

There are several components to lighting the Tavern64 and all are optional. You will need to bridge the pads on JP2 depending on your lighting choices.

1. Per-Key LEDs - Each key (except the 3 macro keys) support a SK6812 mini-e LED which mounts from the back side. 
    
    *Note: There are two LEDs beneath the space bar(s) which may need to be covered if they shine through your case.*
    
2. LED strip - A WS2812B LED strip can be mounted anywhere in your case. It can be installed with our without the per-key LEDs. One of my boards uses an LED strip for under glow lighting.
3. Indicator LEDs - There are 3 slots for optional LED indicator lights. Either a single 5mm LED can be installed in the center, or three 3mm LEDs. I use these for Scroll, Caps, and Num lock indicators. 
    
    *Note: The default firmware only lights up the NUM light if Num lock is OFF.*
    
<a id="a3"></a>
## Encoders & Macro buttons

***Do you want any knobs and/or extra buttons?***

Up to 3 keys can be installed as rotary encoder knobs or as key switches. The availability for one of the keys (KEY #) depends on your placement of the microcontroller. If the MCU is mounted on the back of the board, all 3 keys are available for use.

*Note: There are two mounting holes/tabs on the encoders that connect to GND on the Tavern64 v1 board. These must be clipped off and possibly covered to prevent shorting to ground. This is a design error that will be fixed if there is ever a v2.*

<a id="a4"></a>
## Space bar

***Do you want a normal space bar or split space bar?***

The Tavern64 supports a “full” 6.25u space bar or a split bar with several key size options. Here are the recommended options for a split bar:

- 2u - 2u - 2u
- 2.75u - 1.25u - 2u

*Note: Changing space bar layouts may require de-soldering sockets so be mindful of what you choose!*

<a id="a5"></a>
## OLED display

***What kind of visual display do you want, if any?***

One of two different sized OLED displays can be installed. Both are optional. The top left corner supports a **0.96in 128x64px** display, and the bottom right corner supports a **0.91in 128x32px** display. It doesn’t matter what color display you have, as long as it has 4 pins. Be mindful of how you mount the OLED to the board, as it may affect how it fits in your case.

<a id="a6"></a>
## Buzzer/Speaker

***Do you want a keyboard that can play 8-bit sounds?***

The speaker is completely optional but can give the Tavern64 a little more character. There is also an option for a volume slider switch along with 2 resistors which control the volume level. Resistors with different ratings can be installed for different volume levels. I recommend 100R and 220R.

*Note: I had to modify the version I got so it could be mounted on the bottom side of the board, but it depends on what switch you have. For my low profile board, I opted to not use the volume slider and soldered a wire to bypass the switch.*

<a id="a7"></a>
## Power

The power jumper (JP1) allows flexibility regarding where to source power for the board.

*Note: I have not tested this much and can only verify that the default configuration works.*

<a id="a8"></a>
## Customization!

You’ll need to decide how to customize the rest of your board, including:

1. Switches
2. Keycaps
3. Case
4. Stabilizers

<a id="instructions"></a>
# Instructions

<a id="b1"></a>
## Jumpers

The first step is to bridge the pads on JP1 and JP2 according to your preference.

<a id="c1"></a>
1. **Solder JP1 - Power type**
    
    *Recommendation: Option A*
    
    [https://www.notion.so](https://www.notion.so)
    
    - **Option A** - Indicator + center = 5V power (VBUS)
    
    [https://www.notion.so](https://www.notion.so)
    
    - **Option B** - Non-indicator + center = 3V power (3V3)
    
    [https://www.notion.so](https://www.notion.so)
    
    *Note: this jumper must be bridged for the board to receive power.*
    
    [https://www.notion.so](https://www.notion.so)

<a id="c2"></a>    
2. **Solder JP2 - LED strip**
    
    [https://www.notion.so](https://www.notion.so)
    
    - **Option A** - No bridge = No LED strip installed. (With or without per-key LEDs.)
    
    [https://www.notion.so](https://www.notion.so)
    
    - **Option B** - Indicator + center = LED strip *with* per-key LEDs installed.
    
    [https://www.notion.so](https://www.notion.so)
    
    - **Option C** - Non-indicator + center = LED strip *without* per-key LEDs installed.
    
    [https://www.notion.so](https://www.notion.so)
    
<a id="b2"></a>
## Switches

Be mindful of the placement of the space bar and macro keys. If you have opted to use rotary encoders, it is recommended to install them last because they can get in the way and are not removable without de-soldering.

- **Space bar options**
    - 6.25u full
    
    [https://www.notion.so](https://www.notion.so)
    
    - 2u-2u-2u split
    
    [https://www.notion.so](https://www.notion.so)
    
    - 2.75u-1.25u-2u split
    
    [https://www.notion.so](https://www.notion.so)
    

Each switch has three components to them. The LEDs are optional, but the sockets and diodes are not. It is recommended to solder one type of component at a time to each key on the board. (e.g. solder the sockets first, then the diodes, then the LEDs).

<a id="c3"></a>
3. **Hot swap sockets**
    - Top option = MX sockets (normal)
    - Bottom option = Choc V2 sockets (low profile)
	
<a id="c4"></a>	
4. **Diodes** (1N4148)
    I recommend pre-bending all of the diodes prior to installation. Make sure they are in the correct orientation! Put a few in at a time, then bend the legs so they hold themselves in place. Use flush cut trimmers to avoid leaving sharp points. Save some of the cut off legs to use as pins for the MCU.
    
<a id="c5"></a>	
5. **Per-Key LEDs** (SK6812 mini-e)

    Use some tweezers to help place the LEDs and make sure it is oriented correctly. The notched leg should match the notched pad.
    
<a id="b3"></a>
## Microcontroller

Unless you are building a low profile board, I recommend using pin headers to make the RP2040 microcontroller removable. I also recommend attaching the MCU to the back of the PCB. Be sure you attach the pins and pin header on the correct side!

If you have a breadboard, you can use it to align the pin headers and solder the pins onto the MCU first (step 7). Then use the MCU to hold the pin headers in alignment as you solder them to the PCB (step 6).

<a id="c6"></a>
6. **Solder the pin headers onto the PCB.**
    
    Make sure these are straight or they won’t align with the pins on the MCU.
    
    [https://www.notion.so](https://www.notion.so)

<a id="c7"></a>    
7. **Solder the pins onto the MCU.**
    
    Use the legs that were clipped off from the diodes earlier as pins for the MCU.
    
    [https://www.notion.so](https://www.notion.so)
    
<a id="b4"></a>
## Speaker

If you opt to have a speaker (🎵 which you should!), then start with the volume switch. For the Tavern64 v1 you will likely need to modify your SP3T switch so you can mount it to the bottom side of the PCB. This will be fixed if there is a v2.

<a id="c8"></a>
8. **Solder the volume switch**

[https://www.notion.so](https://www.notion.so)

If you don’t want to use the volume switch, then solder a wire between the indicated through hole and the single hole (opposite of the 3 holes).

[https://www.notion.so](https://www.notion.so)

If you installed the volume switch, then move onto the resistors next. Both THT and SMD resistors are compatible. I use THT in this guide. The resistance rating determines the volume of the speaker. I recommend using 100R and 220R, but you can use whatever you’d like.

<a id="c9"></a>
9. **Solder resistors**
    - 100R
    - 220R

[https://www.notion.so](https://www.notion.so)

<a id="c10"></a>
10. **Solder buzzer/speaker**

[https://www.notion.so](https://www.notion.so)

<a id="b5"></a>
## OLED Screen

There are two options for OLED screens, if you decide to use one. A higher resolution (128x64px) display will fit in the top left corner of the board, while a lower resolution  (128x32px) display fits in the bottom right corner. Only one can be installed at a time (unless someone smarter than me knows how to use both). If pin headers are used, you must use thinner gauge pins than what comes with the OLED. If the screen came with pins preinstalled, then solder the screen directly to the board.

Be mindful of the spacing of the screen from the board, as it will affect how your case fits.

<a id="c11"></a>
11. **Solder the OLED screen** (choose one)
    1. **0.96” 128x64 display** - top left
        
        [https://www.notion.so](https://www.notion.so)
        
    2. **0.91” 128x32 display** - bottom right
        
        [https://www.notion.so](https://www.notion.so)
        
<a id="b6"></a>
## Other Features

<a id="c12"></a>
12. **Solder indicator LEDs**
<a id="c13"></a>
13. **Solder encoders**
<a id="c14"></a>
14. **Solder LED strip**
