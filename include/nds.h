/*---------------------------------------------------------------------------------

	Copyright (C) 2005
		Michael Noland (joat)
		Jason Rogers (dovoto)
		Dave Murphy (WinterMute)

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:


	1.	The origin of this software must not be misrepresented; you
		must not claim that you wrote the original software. If you use
		this software in a product, an acknowledgment in the product
		documentation would be appreciated but is not required.

	2.	Altered source versions must be plainly marked as such, and
		must not be misrepresented as being the original software.

	3.	This notice may not be removed or altered from any source
		distribution.

---------------------------------------------------------------------------------*/
/*! \file nds.h
\brief the master include file for nds applications.
*/

/*!
 \mainpage Libnds Documentation


 \section intro Introduction
 Welcome to the libnds reference documentation.

 \section video_2D_api 2D engine API
 - \ref video.h "General video"
 - \ref background.h "2D Background Layers"
 - \ref sprite.h "2D Sprites"

 \section video_3D_api 3D engine API
  - \ref videoGL.h "OpenGL (ish)"
  - \ref boxtest.h "Box Test"
  - \ref postest.h "Position test"
  - \ref gl2d.h "Simple DS 2D rendering using the 3d core"

 \section audio_api Audio API
 - \ref sound.h "Simple Sound Engine"
 - <a href="https://maxmod.devkitpro.org/ref">Maxmod</a>

 \section math_api Math
  - \ref math.h "Hardware Assisted Math"
  - \ref trig_lut.h "Fixed point trigenometry functions"

 \section memory_api Memory
 - \ref memory.h "General memory definitions"
 - \ref memory.h "nds and gba header structure"
 - \ref dma.h "Direct Memory Access"

 \section system_api System
 - \ref ndstypes.h "Custom DS types"
 - \ref system.h "Hardware Initilization"
 - \ref bios.h "Bios"
 - \ref cache.h "ARM 9 Cache"
 - \ref interrupts.h "Interrupts"
 - \ref fifocommon.h "Fifo"
 - \ref timers.h "Timers"

 \section user_io_api User Input/ouput
 - \ref arm9/input.h "Keypad and Touch pad"
 - \ref keyboard.h "Keyboard"
 - \ref console.h "Console and Debug Printing"

 \section utility_api Utility
 - \ref decompress.h "Decompression"
 - \ref image.h "Image Manipulation"
 - \ref pcx.h "PCX file loader"
 - \ref dynamicArray.h "General Purpose dynamic array implementation"
 - \ref linkedlist.h "General purpose linked list implementation"

 \section peripheral_api Custom Peripherals
 - \ref rumble.h "Rumble Pack"
 - \ref ndsmotion.h "DS Motion Pack"
 - \ref piano.h "DS Easy Piano Controller"

 \section debug_api Debugging
 - \ref console.h "Debug via printf to DS screen or NO$GBA"
 - \ref debug.h "Send message to NO$GBA"
 - \ref sassert.h "simple assert"



 \section external_links Usefull links
 - <a href="http://www.devkitpro.org/">devkitPro</a>
 - <a href="https://github.com/devkitPro/">devkitPro github</a>


 \section games Example Games
 - <a href="http://rel.phatcode.net/index.php?action=contents&item=Bubble_Fight_EX_DS">Bubble Fight EX</a>
 - <a href="http://rel.phatcode.net/index.php?action=contents&item=Space-Impakto-DS">Space Impakto DS</a>

*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../src/libversion.h"
#include "../src/ndstypes.h"
#include "../src/bios.h"
#include "../src/card.h"
#include "../src/debug.h"
#include "../src/dma.h"
#include "../src/interrupts.h"
#include "../src/ipc.h"
#include "../src/memory.h"
#include "../src/system.h"
#include "../src/timers.h"
#include "../src/fifocommon.h"
#include "../src/touch.h"
#include "../src/input.h"
#include "../src/sha1.h"

#include "../src/arm9/dynamicArray.h"
#include "../src/arm9/linkedlist.h"
#include "../src/arm9/background.h"
#include "../src/arm9/boxtest.h"
#include "../src/arm9/cache.h"
#include "../src/arm9/console.h"
#include "../src/arm9/decompress.h"
#include "../src/arm9/exceptions.h"
#include "../src/arm9/guitarGrip.h"
#include "../src/arm9/image.h"
#include "../src/arm9/input.h"
#include "../src/arm9/keyboard.h"
#include "../src/arm9/math.h"
#include "../src/arm9/paddle.h"
#include "../src/arm9/pcx.h"
#include "../src/arm9/piano.h"
#include "../src/arm9/rumble.h"
#include "../src/arm9/sassert.h"
#include "../src/arm9/sound.h"
#include "../src/arm9/sprite.h"
#include "../src/arm9/window.h"
#include "../src/arm9/trig_lut.h"
#include "../src/arm9/video.h"
#include "../src/arm9/videoGL.h"
#include "../src/arm9/dldi/nand.h"

#ifdef __cplusplus
}
#endif


