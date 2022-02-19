/*
 * settings_shapeoko375.h - Shapeoko2 500mm table
 * This file is part of the TinyG project
 *
 * Copyright (c) 2010 - 2014 Alden S. Hart, Jr.
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/* Note: The values in this file are the default settings that are loaded
 * 		 into a virgin EEPROM, and can be changed using the config commands.
 *		 After initial load the EEPROM values (or changed values) are used.
 *
 *		 System and hardware settings that you shouldn't need to change
 *		 are in system.h  Application settings that also shouldn't need
 *		 to be changed are in tinyg.h
 */

/***********************************************************************/
/**** Shapeoko2 500mm profile ********************************************/
/***********************************************************************/

// ***> NOTE: The init message must be a single line with no CRs or LFs
#define INIT_MESSAGE "Initializing configs to Shapeoko2 500mm profile"

#define JUNCTION_DEVIATION		0.01	// default value, in mm - smaller is faster
#define JUNCTION_ACCELERATION	2000000	// 2 million - centripetal acceleration around corners

// *** settings.h overrides ***

#undef COMM_MODE
#define COMM_MODE				JSON_MODE

#undef JSON_VERBOSITY
#define JSON_VERBOSITY 			JV_VERBOSE

#undef SWITCH_TYPE
#define SWITCH_TYPE 			SW_TYPE_NORMALLY_CLOSED	// one of: SW_TYPE_NORMALLY_OPEN, SW_TYPE_NORMALLY_CLOSED

// *** motor settings ***

#define M1_MOTOR_MAP 			AXIS_X	// 1ma
#define M1_STEP_ANGLE			1.8		// 1sa
#define M1_TRAVEL_PER_REV		40.00	// 1tr
#define M1_MICROSTEPS			8		// 1mi		1,2,4,8
#define M1_POLARITY				1		// 1po		0=normal, 1=reversed
#define M1_POWER_MODE			2		// 1pm		TRUE=low power idle enabled

#define M2_MOTOR_MAP			AXIS_Y  // Y1 - left side of machine
#define M2_STEP_ANGLE			1.8
#define M2_TRAVEL_PER_REV		40.00
#define M2_MICROSTEPS			8
#define M2_POLARITY				1
#define M2_POWER_MODE			2

#define M3_MOTOR_MAP			AXIS_Y  // Y2 - right sif of machine
#define M3_STEP_ANGLE			1.8
#define M3_TRAVEL_PER_REV		40.00
#define M3_MICROSTEPS			8
#define M3_POLARITY				0
#define M3_POWER_MODE			2

#define M4_MOTOR_MAP			AXIS_Z
#define M4_STEP_ANGLE			1.8
#define M4_TRAVEL_PER_REV		2.1166
#define M4_MICROSTEPS			8
#define M4_POLARITY				1
#define M4_POWER_MODE			2

#define M5_MOTOR_MAP			AXIS_DISABLED
#define M5_STEP_ANGLE			1.8
#define M5_TRAVEL_PER_REV		360		// degrees per motor rev
#define M5_MICROSTEPS			8
#define M5_POLARITY				0
#define M5_POWER_MODE			MOTOR_POWER_MODE

#define M6_MOTOR_MAP			AXIS_DISABLED
#define M6_STEP_ANGLE			1.8
#define M6_TRAVEL_PER_REV		360
#define M6_MICROSTEPS			8
#define M6_POLARITY				0
#define M6_POWER_MODE			MOTOR_POWER_MODE

// *** axis settings ***

// These are relative conservative values for a well-tuned Shapeoko2 or similar XY belt / Z screw machine

#define X_AXIS_MODE				AXIS_STANDARD		// xam		see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX			16000 				// xvm		G0 max velocity in mm/min
#define X_FEEDRATE_MAX			X_VELOCITY_MAX		// xfr 		G1 max feed rate in mm/min
#define X_TRAVEL_MIN			0					// xtn		minimum travel
#define X_TRAVEL_MAX			290					// xtm		maximum travel (travel between switches or crashes)
#define X_JERK_MAX				5000				// xjm		yes, that's "5 billion" mm/(min^3)
#define X_JERK_HOMING			10000				// xjh
#define X_JUNCTION_DEVIATION	JUNCTION_DEVIATION	// xjd
#define X_SWITCH_MODE_MIN		SW_MODE_HOMING		// xsn		SW_MODE_DISABLED, SW_MODE_HOMING, SW_MODE_LIMIT, SW_MODE_HOMING_LIMIT
#define X_SWITCH_MODE_MAX 		SW_MODE_DISABLED	// xsx		SW_MODE_DISABLED, SW_MODE_HOMING, SW_MODE_LIMIT, SW_MODE_HOMING_LIMIT
#define X_SEARCH_VELOCITY		3000				// xsv		minus means move to minimum switch
#define X_LATCH_VELOCITY		100					// xlv		mm/min
#define X_LATCH_BACKOFF			10					// xlb		mm
#define X_ZERO_BACKOFF			2					// xzb		mm

#define Y_AXIS_MODE				AXIS_STANDARD
#define Y_VELOCITY_MAX			16000
#define Y_FEEDRATE_MAX			Y_VELOCITY_MAX
#define Y_TRAVEL_MIN			0
#define Y_TRAVEL_MAX			320
#define Y_JERK_MAX				5000
#define Y_JERK_HOMING			10000				// xjh
#define Y_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define Y_SWITCH_MODE_MIN		SW_MODE_HOMING
#define Y_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define Y_SEARCH_VELOCITY		3000
#define Y_LATCH_VELOCITY		100
#define Y_LATCH_BACKOFF			10
#define Y_ZERO_BACKOFF			2

#define Z_AXIS_MODE				AXIS_STANDARD
#define Z_VELOCITY_MAX			1000
#define Z_FEEDRATE_MAX			Z_VELOCITY_MAX
#define Z_TRAVEL_MAX			0
#define Z_TRAVEL_MIN			-120                // this is approximate as Z depth depends on tooling
                                                    // value must be large enough to guarantee return to Zmax during homing
#define Z_JERK_MAX				50					// 50,000,000
#define Z_JERK_HOMING			1000
#define Z_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define Z_SWITCH_MODE_MIN		SW_MODE_DISABLED
#define Z_SWITCH_MODE_MAX		SW_MODE_HOMING
#define Z_SEARCH_VELOCITY		Z_VELOCITY_MAX
#define Z_LATCH_VELOCITY		100
#define Z_LATCH_BACKOFF			10
#define Z_ZERO_BACKOFF			3

/***************************************************************************************
 * A Axis rotary values are chosen to make the motor react the same as X for testing
 *
 * To calculate the speeds here, in Wolfram Alpha-speak:
 *
 *   c=2*pi*r, r=0.609, d=c/360, s=((S*60)/d), S=40 for s
 *   c=2*pi*r, r=5.30516, d=c/360, s=((S*60)/d), S=40 for s
 *
 * Change r to A_RADIUS, and S to the desired speed, in mm/s or mm/s/s/s.
 *
 * It will return s= as the value you want to enter.
 *
 * If the value is over 1 million, the code will divide it by 1 million,
 * so you have to pre-multiply it by 1000000.0. (The value is in millions, btw.)
 *
 * Note that you need these to be floating point values, so always have a .0 at the end!
 *
 ***************************************************************************************/

#define A_AXIS_MODE 			AXIS_RADIUS
#define A_RADIUS 				5.30516             //
#define A_VELOCITY_MAX          25920.0             // ~40 mm/s, 2,400 mm/min
#define A_FEEDRATE_MAX 			25920.0/2.0         // ~20 mm/s, 1,200 mm/min
#define A_TRAVEL_MIN 			-1                  // identical mean no homing will occur
#define A_TRAVEL_MAX 			-1
#define A_JERK_MAX 				324000              // 1,000 million mm/min^3
                                                    // * a million IF it's over a million
                                                    // c=2*pi*r, r=5.30516476972984, d=c/360, s=((1000*60)/d)
#define A_JERK_HOMING			A_JERK_MAX
#define A_JUNCTION_DEVIATION	0.1
#define A_SWITCH_MODE_MIN		SW_MODE_HOMING
#define A_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define A_SEARCH_VELOCITY 		2000
#define A_LATCH_VELOCITY 		2000
#define A_LATCH_BACKOFF 		5
#define A_ZERO_BACKOFF 			2

/*
#define A_AXIS_MODE				AXIS_STANDARD
#define A_VELOCITY_MAX			60000
#define A_FEEDRATE_MAX			48000
#define A_JERK_MAX				24000				// yes, 24 billion
#define A_JERK_HOMING			A_JERK_MAX
#define A_RADIUS				1.0
#define A_SWITCH_MODE_MIN		SW_MODE_HOMING
#define A_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define A_SEARCH_VELOCITY		6000
#define A_LATCH_VELOCITY		1000
#define A_LATCH_BACKOFF			5
#define A_ZERO_BACKOFF			2
*/

#define B_AXIS_MODE				AXIS_DISABLED
#define B_VELOCITY_MAX			3600
#define B_FEEDRATE_MAX			B_VELOCITY_MAX
#define B_TRAVEL_MAX			-1
#define B_TRAVEL_MIN			-1
#define B_JERK_MAX				20
#define B_JERK_HOMING			B_JERK_MAX
#define B_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define B_RADIUS				1
#define B_SWITCH_MODE_MIN		SW_MODE_HOMING
#define B_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define B_SEARCH_VELOCITY		6000
#define B_LATCH_VELOCITY		1000
#define B_LATCH_BACKOFF			5
#define B_ZERO_BACKOFF			2

#define C_AXIS_MODE				AXIS_DISABLED
#define C_VELOCITY_MAX			3600
#define C_FEEDRATE_MAX			C_VELOCITY_MAX
#define C_TRAVEL_MAX			-1
#define C_TRAVEL_MIN			-1
#define C_JERK_MAX				20
#define C_JERK_HOMING			C_JERK_MAX
#define C_JUNCTION_DEVIATION	JUNCTION_DEVIATION
#define C_RADIUS				1
#define C_SWITCH_MODE_MIN		SW_MODE_HOMING
#define C_SWITCH_MODE_MAX		SW_MODE_DISABLED
#define C_SEARCH_VELOCITY		6000
#define C_LATCH_VELOCITY		1000
#define C_LATCH_BACKOFF			5
#define C_ZERO_BACKOFF			2

// *** DEFAULT COORDINATE SYSTEM OFFSETS ***
// Our convention is:
//	- leave G54 in machine coordinates to act as a persistent absolute coordinate system
//	- set G55 to be a zero in the middle of the table
//	- no action for the others

#define G54_X_OFFSET 0			// G54 is traditionally set to all zeros
#define G54_Y_OFFSET 0
#define G54_Z_OFFSET 0
#define G54_A_OFFSET 0
#define G54_B_OFFSET 0
#define G54_C_OFFSET 0

#define G55_X_OFFSET (X_TRAVEL_MAX/2)	// set g55 to middle of table
#define G55_Y_OFFSET (Y_TRAVEL_MAX/2)
#define G55_Z_OFFSET 0
#define G55_A_OFFSET 0
#define G55_B_OFFSET 0
#define G55_C_OFFSET 0

#define G56_X_OFFSET 0
#define G56_Y_OFFSET 0
#define G56_Z_OFFSET 0
#define G56_A_OFFSET 0
#define G56_B_OFFSET 0
#define G56_C_OFFSET 0

#define G57_X_OFFSET 0
#define G57_Y_OFFSET 0
#define G57_Z_OFFSET 0
#define G57_A_OFFSET 0
#define G57_B_OFFSET 0
#define G57_C_OFFSET 0

#define G58_X_OFFSET 0
#define G58_Y_OFFSET 0
#define G58_Z_OFFSET 0
#define G58_A_OFFSET 0
#define G58_B_OFFSET 0
#define G58_C_OFFSET 0

#define G59_X_OFFSET 0
#define G59_Y_OFFSET 0
#define G59_Z_OFFSET 0
#define G59_A_OFFSET 0
#define G59_B_OFFSET 0
#define G59_C_OFFSET 0

// *** Tool Table Defaults *** //

#ifndef TT1_X_OFFSET
#define TT1_X_OFFSET 2
#endif
#ifndef TT1_Y_OFFSET
#define TT1_Y_OFFSET 2
#endif
#ifndef TT1_Z_OFFSET
#define TT1_Z_OFFSET 0
#endif
#ifndef TT1_U_OFFSET
#define TT1_U_OFFSET 0
#endif
#ifndef TT1_V_OFFSET
#define TT1_V_OFFSET 0
#endif
#ifndef TT1_W_OFFSET
#define TT1_W_OFFSET 0
#endif
#ifndef TT1_A_OFFSET
#define TT1_A_OFFSET 0
#endif
#ifndef TT1_B_OFFSET
#define TT1_B_OFFSET 0
#endif
#ifndef TT1_C_OFFSET
#define TT1_C_OFFSET 0
#endif

#ifndef TT2_X_OFFSET
#define TT2_X_OFFSET 0
#endif
#ifndef TT2_Y_OFFSET
#define TT2_Y_OFFSET 0
#endif
#ifndef TT2_Z_OFFSET
#define TT2_Z_OFFSET 0
#endif
#ifndef TT2_U_OFFSET
#define TT2_U_OFFSET 0
#endif
#ifndef TT2_V_OFFSET
#define TT2_V_OFFSET 0
#endif
#ifndef TT2_W_OFFSET
#define TT2_W_OFFSET 0
#endif
#ifndef TT2_A_OFFSET
#define TT2_A_OFFSET 0
#endif
#ifndef TT2_B_OFFSET
#define TT2_B_OFFSET 0
#endif
#ifndef TT2_C_OFFSET
#define TT2_C_OFFSET 0
#endif

#ifndef TT3_X_OFFSET
#define TT3_X_OFFSET 0
#endif
#ifndef TT3_Y_OFFSET
#define TT3_Y_OFFSET 0
#endif
#ifndef TT3_Z_OFFSET
#define TT3_Z_OFFSET 0
#endif
#ifndef TT3_U_OFFSET
#define TT3_U_OFFSET 0
#endif
#ifndef TT3_V_OFFSET
#define TT3_V_OFFSET 0
#endif
#ifndef TT3_W_OFFSET
#define TT3_W_OFFSET 0
#endif
#ifndef TT3_A_OFFSET
#define TT3_A_OFFSET 0
#endif
#ifndef TT3_B_OFFSET
#define TT3_B_OFFSET 0
#endif
#ifndef TT3_C_OFFSET
#define TT3_C_OFFSET 0
#endif

#ifndef TT4_X_OFFSET
#define TT4_X_OFFSET 0
#endif
#ifndef TT4_Y_OFFSET
#define TT4_Y_OFFSET 0
#endif
#ifndef TT4_Z_OFFSET
#define TT4_Z_OFFSET 0
#endif
#ifndef TT4_U_OFFSET
#define TT4_U_OFFSET 0
#endif
#ifndef TT4_V_OFFSET
#define TT4_V_OFFSET 0
#endif
#ifndef TT4_W_OFFSET
#define TT4_W_OFFSET 0
#endif
#ifndef TT4_A_OFFSET
#define TT4_A_OFFSET 0
#endif
#ifndef TT4_B_OFFSET
#define TT4_B_OFFSET 0
#endif
#ifndef TT4_C_OFFSET
#define TT4_C_OFFSET 0
#endif

#ifndef TT5_X_OFFSET
#define TT5_X_OFFSET 0
#endif
#ifndef TT5_Y_OFFSET
#define TT5_Y_OFFSET 0
#endif
#ifndef TT5_Z_OFFSET
#define TT5_Z_OFFSET 0
#endif
#ifndef TT5_U_OFFSET
#define TT5_U_OFFSET 0
#endif
#ifndef TT5_V_OFFSET
#define TT5_V_OFFSET 0
#endif
#ifndef TT5_W_OFFSET
#define TT5_W_OFFSET 0
#endif
#ifndef TT5_A_OFFSET
#define TT5_A_OFFSET 0
#endif
#ifndef TT5_B_OFFSET
#define TT5_B_OFFSET 0
#endif
#ifndef TT5_C_OFFSET
#define TT5_C_OFFSET 0
#endif

#ifndef TT6_X_OFFSET
#define TT6_X_OFFSET 0
#endif
#ifndef TT6_Y_OFFSET
#define TT6_Y_OFFSET 0
#endif
#ifndef TT6_Z_OFFSET
#define TT6_Z_OFFSET 0
#endif
#ifndef TT6_U_OFFSET
#define TT6_U_OFFSET 0
#endif
#ifndef TT6_V_OFFSET
#define TT6_V_OFFSET 0
#endif
#ifndef TT6_W_OFFSET
#define TT6_W_OFFSET 0
#endif
#ifndef TT6_A_OFFSET
#define TT6_A_OFFSET 0
#endif
#ifndef TT6_B_OFFSET
#define TT6_B_OFFSET 0
#endif
#ifndef TT6_C_OFFSET
#define TT6_C_OFFSET 0
#endif

#ifndef TT7_X_OFFSET
#define TT7_X_OFFSET 0
#endif
#ifndef TT7_Y_OFFSET
#define TT7_Y_OFFSET 0
#endif
#ifndef TT7_Z_OFFSET
#define TT7_Z_OFFSET 0
#endif
#ifndef TT7_U_OFFSET
#define TT7_U_OFFSET 0
#endif
#ifndef TT7_V_OFFSET
#define TT7_V_OFFSET 0
#endif
#ifndef TT7_W_OFFSET
#define TT7_W_OFFSET 0
#endif
#ifndef TT7_A_OFFSET
#define TT7_A_OFFSET 0
#endif
#ifndef TT7_B_OFFSET
#define TT7_B_OFFSET 0
#endif
#ifndef TT7_C_OFFSET
#define TT7_C_OFFSET 0
#endif

#ifndef TT8_X_OFFSET
#define TT8_X_OFFSET 0
#endif
#ifndef TT8_Y_OFFSET
#define TT8_Y_OFFSET 0
#endif
#ifndef TT8_U_OFFSET
#define TT8_U_OFFSET 0
#endif
#ifndef TT8_V_OFFSET
#define TT8_V_OFFSET 0
#endif
#ifndef TT8_W_OFFSET
#define TT8_W_OFFSET 0
#endif
#ifndef TT8_Z_OFFSET
#define TT8_Z_OFFSET 0
#endif
#ifndef TT8_A_OFFSET
#define TT8_A_OFFSET 0
#endif
#ifndef TT8_B_OFFSET
#define TT8_B_OFFSET 0
#endif
#ifndef TT8_C_OFFSET
#define TT8_C_OFFSET 0
#endif

#ifndef TT9_X_OFFSET
#define TT9_X_OFFSET 0
#endif
#ifndef TT9_Y_OFFSET
#define TT9_Y_OFFSET 0
#endif
#ifndef TT9_Z_OFFSET
#define TT9_Z_OFFSET 0
#endif
#ifndef TT9_U_OFFSET
#define TT9_U_OFFSET 0
#endif
#ifndef TT9_V_OFFSET
#define TT9_V_OFFSET 0
#endif
#ifndef TT9_W_OFFSET
#define TT9_W_OFFSET 0
#endif
#ifndef TT9_A_OFFSET
#define TT9_A_OFFSET 0
#endif
#ifndef TT9_B_OFFSET
#define TT9_B_OFFSET 0
#endif
#ifndef TT9_C_OFFSET
#define TT9_C_OFFSET 0
#endif

#ifndef TT10_X_OFFSET
#define TT10_X_OFFSET 0
#endif
#ifndef TT10_Y_OFFSET
#define TT10_Y_OFFSET 0
#endif
#ifndef TT10_Z_OFFSET
#define TT10_Z_OFFSET 0
#endif
#ifndef TT10_U_OFFSET
#define TT10_U_OFFSET 0
#endif
#ifndef TT10_V_OFFSET
#define TT10_V_OFFSET 0
#endif
#ifndef TT10_W_OFFSET
#define TT10_W_OFFSET 0
#endif
#ifndef TT10_A_OFFSET
#define TT10_A_OFFSET 0
#endif
#ifndef TT10_B_OFFSET
#define TT10_B_OFFSET 0
#endif
#ifndef TT10_C_OFFSET
#define TT10_C_OFFSET 0
#endif

#ifndef TT11_X_OFFSET
#define TT11_X_OFFSET 0
#endif
#ifndef TT11_Y_OFFSET
#define TT11_Y_OFFSET 0
#endif
#ifndef TT11_Z_OFFSET
#define TT11_Z_OFFSET 0
#endif
#ifndef TT11_U_OFFSET
#define TT11_U_OFFSET 0
#endif
#ifndef TT11_V_OFFSET
#define TT11_V_OFFSET 0
#endif
#ifndef TT11_W_OFFSET
#define TT11_W_OFFSET 0
#endif
#ifndef TT11_A_OFFSET
#define TT11_A_OFFSET 0
#endif
#ifndef TT11_B_OFFSET
#define TT11_B_OFFSET 0
#endif
#ifndef TT11_C_OFFSET
#define TT11_C_OFFSET 0
#endif

#ifndef TT12_X_OFFSET
#define TT12_X_OFFSET 0
#endif
#ifndef TT12_Y_OFFSET
#define TT12_Y_OFFSET 0
#endif
#ifndef TT12_Z_OFFSET
#define TT12_Z_OFFSET 0
#endif
#ifndef TT12_U_OFFSET
#define TT12_U_OFFSET 0
#endif
#ifndef TT12_V_OFFSET
#define TT12_V_OFFSET 0
#endif
#ifndef TT12_W_OFFSET
#define TT12_W_OFFSET 0
#endif
#ifndef TT12_A_OFFSET
#define TT12_A_OFFSET 0
#endif
#ifndef TT12_B_OFFSET
#define TT12_B_OFFSET 0
#endif
#ifndef TT12_C_OFFSET
#define TT12_C_OFFSET 0
#endif

#ifndef TT13_X_OFFSET
#define TT13_X_OFFSET 0
#endif
#ifndef TT13_Y_OFFSET
#define TT13_Y_OFFSET 0
#endif
#ifndef TT13_Z_OFFSET
#define TT13_Z_OFFSET 0
#endif
#ifndef TT13_U_OFFSET
#define TT13_U_OFFSET 0
#endif
#ifndef TT13_V_OFFSET
#define TT13_V_OFFSET 0
#endif
#ifndef TT13_W_OFFSET
#define TT13_W_OFFSET 0
#endif
#ifndef TT13_A_OFFSET
#define TT13_A_OFFSET 0
#endif
#ifndef TT13_B_OFFSET
#define TT13_B_OFFSET 0
#endif
#ifndef TT13_C_OFFSET
#define TT13_C_OFFSET 0
#endif

#ifndef TT14_X_OFFSET
#define TT14_X_OFFSET 0
#endif
#ifndef TT14_Y_OFFSET
#define TT14_Y_OFFSET 0
#endif
#ifndef TT14_Z_OFFSET
#define TT14_Z_OFFSET 0
#endif
#ifndef TT14_U_OFFSET
#define TT14_U_OFFSET 0
#endif
#ifndef TT14_V_OFFSET
#define TT14_V_OFFSET 0
#endif
#ifndef TT14_W_OFFSET
#define TT14_W_OFFSET 0
#endif
#ifndef TT14_A_OFFSET
#define TT14_A_OFFSET 0
#endif
#ifndef TT14_B_OFFSET
#define TT14_B_OFFSET 0
#endif
#ifndef TT14_C_OFFSET
#define TT14_C_OFFSET 0
#endif

#ifndef TT15_X_OFFSET
#define TT15_X_OFFSET 0
#endif
#ifndef TT15_Y_OFFSET
#define TT15_Y_OFFSET 0
#endif
#ifndef TT15_Z_OFFSET
#define TT15_Z_OFFSET 0
#endif
#ifndef TT15_U_OFFSET
#define TT15_U_OFFSET 0
#endif
#ifndef TT15_V_OFFSET
#define TT15_V_OFFSET 0
#endif
#ifndef TT15_W_OFFSET
#define TT15_W_OFFSET 0
#endif
#ifndef TT15_A_OFFSET
#define TT15_A_OFFSET 0
#endif
#ifndef TT15_B_OFFSET
#define TT15_B_OFFSET 0
#endif
#ifndef TT15_C_OFFSET
#define TT15_C_OFFSET 0
#endif

#ifndef TT16_X_OFFSET
#define TT16_X_OFFSET 0
#endif
#ifndef TT16_Y_OFFSET
#define TT16_Y_OFFSET 0
#endif
#ifndef TT16_Z_OFFSET
#define TT16_Z_OFFSET 0
#endif
#ifndef TT16_U_OFFSET
#define TT16_U_OFFSET 0
#endif
#ifndef TT16_V_OFFSET
#define TT16_V_OFFSET 0
#endif
#ifndef TT16_W_OFFSET
#define TT16_W_OFFSET 0
#endif
#ifndef TT16_A_OFFSET
#define TT16_A_OFFSET 0
#endif
#ifndef TT16_B_OFFSET
#define TT16_B_OFFSET 0
#endif
#ifndef TT16_C_OFFSET
#define TT16_C_OFFSET 0
#endif

#ifndef TT17_X_OFFSET
#define TT17_X_OFFSET 0
#endif
#ifndef TT17_Y_OFFSET
#define TT17_Y_OFFSET 0
#endif
#ifndef TT17_Z_OFFSET
#define TT17_Z_OFFSET 0
#endif
#ifndef TT17_U_OFFSET
#define TT17_U_OFFSET 0
#endif
#ifndef TT17_V_OFFSET
#define TT17_V_OFFSET 0
#endif
#ifndef TT17_W_OFFSET
#define TT17_W_OFFSET 0
#endif
#ifndef TT17_A_OFFSET
#define TT17_A_OFFSET 0
#endif
#ifndef TT17_B_OFFSET
#define TT17_B_OFFSET 0
#endif
#ifndef TT17_C_OFFSET
#define TT17_C_OFFSET 0
#endif

#ifndef TT18_X_OFFSET
#define TT18_X_OFFSET 0
#endif
#ifndef TT18_Y_OFFSET
#define TT18_Y_OFFSET 0
#endif
#ifndef TT18_Z_OFFSET
#define TT18_Z_OFFSET 0
#endif
#ifndef TT18_U_OFFSET
#define TT18_U_OFFSET 0
#endif
#ifndef TT18_V_OFFSET
#define TT18_V_OFFSET 0
#endif
#ifndef TT18_W_OFFSET
#define TT18_W_OFFSET 0
#endif
#ifndef TT18_A_OFFSET
#define TT18_A_OFFSET 0
#endif
#ifndef TT18_B_OFFSET
#define TT18_B_OFFSET 0
#endif
#ifndef TT18_C_OFFSET
#define TT18_C_OFFSET 0
#endif

#ifndef TT19_X_OFFSET
#define TT19_X_OFFSET 0
#endif
#ifndef TT19_Y_OFFSET
#define TT19_Y_OFFSET 0
#endif
#ifndef TT19_Z_OFFSET
#define TT19_Z_OFFSET 0
#endif
#ifndef TT19_U_OFFSET
#define TT19_U_OFFSET 0
#endif
#ifndef TT19_V_OFFSET
#define TT19_V_OFFSET 0
#endif
#ifndef TT19_W_OFFSET
#define TT19_W_OFFSET 0
#endif
#ifndef TT19_A_OFFSET
#define TT19_A_OFFSET 0
#endif
#ifndef TT19_B_OFFSET
#define TT19_B_OFFSET 0
#endif
#ifndef TT19_C_OFFSET
#define TT19_C_OFFSET 0
#endif

#ifndef TT20_X_OFFSET
#define TT20_X_OFFSET 0
#endif
#ifndef TT20_Y_OFFSET
#define TT20_Y_OFFSET 0
#endif
#ifndef TT20_Z_OFFSET
#define TT20_Z_OFFSET 0
#endif
#ifndef TT20_U_OFFSET
#define TT20_U_OFFSET 0
#endif
#ifndef TT20_V_OFFSET
#define TT20_V_OFFSET 0
#endif
#ifndef TT20_W_OFFSET
#define TT20_W_OFFSET 0
#endif
#ifndef TT20_A_OFFSET
#define TT20_A_OFFSET 0
#endif
#ifndef TT20_B_OFFSET
#define TT20_B_OFFSET 0
#endif
#ifndef TT20_C_OFFSET
#define TT20_C_OFFSET 0
#endif

#ifndef TT21_X_OFFSET
#define TT21_X_OFFSET 0
#endif
#ifndef TT21_Y_OFFSET
#define TT21_Y_OFFSET 0
#endif
#ifndef TT21_Z_OFFSET
#define TT21_Z_OFFSET 0
#endif
#ifndef TT21_U_OFFSET
#define TT21_U_OFFSET 0
#endif
#ifndef TT21_V_OFFSET
#define TT21_V_OFFSET 0
#endif
#ifndef TT21_W_OFFSET
#define TT21_W_OFFSET 0
#endif
#ifndef TT21_A_OFFSET
#define TT21_A_OFFSET 0
#endif
#ifndef TT21_B_OFFSET
#define TT21_B_OFFSET 0
#endif
#ifndef TT21_C_OFFSET
#define TT21_C_OFFSET 0
#endif

#ifndef TT22_X_OFFSET
#define TT22_X_OFFSET 0
#endif
#ifndef TT22_Y_OFFSET
#define TT22_Y_OFFSET 0
#endif
#ifndef TT22_Z_OFFSET
#define TT22_Z_OFFSET 0
#endif
#ifndef TT22_U_OFFSET
#define TT22_U_OFFSET 0
#endif
#ifndef TT22_V_OFFSET
#define TT22_V_OFFSET 0
#endif
#ifndef TT22_W_OFFSET
#define TT22_W_OFFSET 0
#endif
#ifndef TT22_A_OFFSET
#define TT22_A_OFFSET 0
#endif
#ifndef TT22_B_OFFSET
#define TT22_B_OFFSET 0
#endif
#ifndef TT22_C_OFFSET
#define TT22_C_OFFSET 0
#endif

#ifndef TT23_X_OFFSET
#define TT23_X_OFFSET 0
#endif
#ifndef TT23_Y_OFFSET
#define TT23_Y_OFFSET 0
#endif
#ifndef TT23_Z_OFFSET
#define TT23_Z_OFFSET 0
#endif
#ifndef TT23_U_OFFSET
#define TT23_U_OFFSET 0
#endif
#ifndef TT23_V_OFFSET
#define TT23_V_OFFSET 0
#endif
#ifndef TT23_W_OFFSET
#define TT23_W_OFFSET 0
#endif
#ifndef TT23_A_OFFSET
#define TT23_A_OFFSET 0
#endif
#ifndef TT23_B_OFFSET
#define TT23_B_OFFSET 0
#endif
#ifndef TT23_C_OFFSET
#define TT23_C_OFFSET 0
#endif

#ifndef TT24_X_OFFSET
#define TT24_X_OFFSET 0
#endif
#ifndef TT24_Y_OFFSET
#define TT24_Y_OFFSET 0
#endif
#ifndef TT24_Z_OFFSET
#define TT24_Z_OFFSET 0
#endif
#ifndef TT24_U_OFFSET
#define TT24_U_OFFSET 0
#endif
#ifndef TT24_V_OFFSET
#define TT24_V_OFFSET 0
#endif
#ifndef TT24_W_OFFSET
#define TT24_W_OFFSET 0
#endif
#ifndef TT24_A_OFFSET
#define TT24_A_OFFSET 0
#endif
#ifndef TT24_B_OFFSET
#define TT24_B_OFFSET 0
#endif
#ifndef TT24_C_OFFSET
#define TT24_C_OFFSET 0
#endif

#ifndef TT25_X_OFFSET
#define TT25_X_OFFSET 0
#endif
#ifndef TT25_Y_OFFSET
#define TT25_Y_OFFSET 0
#endif
#ifndef TT25_Z_OFFSET
#define TT25_Z_OFFSET 0
#endif
#ifndef TT25_U_OFFSET
#define TT25_U_OFFSET 0
#endif
#ifndef TT25_V_OFFSET
#define TT25_V_OFFSET 0
#endif
#ifndef TT25_W_OFFSET
#define TT25_W_OFFSET 0
#endif
#ifndef TT25_A_OFFSET
#define TT25_A_OFFSET 0
#endif
#ifndef TT25_B_OFFSET
#define TT25_B_OFFSET 0
#endif
#ifndef TT25_C_OFFSET
#define TT25_C_OFFSET 0
#endif

#ifndef TT26_X_OFFSET
#define TT26_X_OFFSET 0
#endif
#ifndef TT26_Y_OFFSET
#define TT26_Y_OFFSET 0
#endif
#ifndef TT26_Z_OFFSET
#define TT26_Z_OFFSET 0
#endif
#ifndef TT26_U_OFFSET
#define TT26_U_OFFSET 0
#endif
#ifndef TT26_V_OFFSET
#define TT26_V_OFFSET 0
#endif
#ifndef TT26_W_OFFSET
#define TT26_W_OFFSET 0
#endif
#ifndef TT26_A_OFFSET
#define TT26_A_OFFSET 0
#endif
#ifndef TT26_B_OFFSET
#define TT26_B_OFFSET 0
#endif
#ifndef TT26_C_OFFSET
#define TT26_C_OFFSET 0
#endif

#ifndef TT27_X_OFFSET
#define TT27_X_OFFSET 0
#endif
#ifndef TT27_Y_OFFSET
#define TT27_Y_OFFSET 0
#endif
#ifndef TT27_Z_OFFSET
#define TT27_Z_OFFSET 0
#endif
#ifndef TT27_U_OFFSET
#define TT27_U_OFFSET 0
#endif
#ifndef TT27_V_OFFSET
#define TT27_V_OFFSET 0
#endif
#ifndef TT27_W_OFFSET
#define TT27_W_OFFSET 0
#endif
#ifndef TT27_A_OFFSET
#define TT27_A_OFFSET 0
#endif
#ifndef TT27_B_OFFSET
#define TT27_B_OFFSET 0
#endif
#ifndef TT27_C_OFFSET
#define TT27_C_OFFSET 0
#endif

#ifndef TT28_X_OFFSET
#define TT28_X_OFFSET 0
#endif
#ifndef TT28_Y_OFFSET
#define TT28_Y_OFFSET 0
#endif
#ifndef TT28_Z_OFFSET
#define TT28_Z_OFFSET 0
#endif
#ifndef TT28_U_OFFSET
#define TT28_U_OFFSET 0
#endif
#ifndef TT28_V_OFFSET
#define TT28_V_OFFSET 0
#endif
#ifndef TT28_W_OFFSET
#define TT28_W_OFFSET 0
#endif
#ifndef TT28_A_OFFSET
#define TT28_A_OFFSET 0
#endif
#ifndef TT28_B_OFFSET
#define TT28_B_OFFSET 0
#endif
#ifndef TT28_C_OFFSET
#define TT28_C_OFFSET 0
#endif

#ifndef TT29_X_OFFSET
#define TT29_X_OFFSET 0
#endif
#ifndef TT29_Y_OFFSET
#define TT29_Y_OFFSET 0
#endif
#ifndef TT29_Z_OFFSET
#define TT29_Z_OFFSET 0
#endif
#ifndef TT29_U_OFFSET
#define TT29_U_OFFSET 0
#endif
#ifndef TT29_V_OFFSET
#define TT29_V_OFFSET 0
#endif
#ifndef TT29_W_OFFSET
#define TT29_W_OFFSET 0
#endif
#ifndef TT29_A_OFFSET
#define TT29_A_OFFSET 0
#endif
#ifndef TT29_B_OFFSET
#define TT29_B_OFFSET 0
#endif
#ifndef TT29_C_OFFSET
#define TT29_C_OFFSET 0
#endif

#ifndef TT30_X_OFFSET
#define TT30_X_OFFSET 0
#endif
#ifndef TT30_Y_OFFSET
#define TT30_Y_OFFSET 0
#endif
#ifndef TT30_Z_OFFSET
#define TT30_Z_OFFSET 0
#endif
#ifndef TT30_U_OFFSET
#define TT30_U_OFFSET 0
#endif
#ifndef TT30_V_OFFSET
#define TT30_V_OFFSET 0
#endif
#ifndef TT30_W_OFFSET
#define TT30_W_OFFSET 0
#endif
#ifndef TT30_A_OFFSET
#define TT30_A_OFFSET 0
#endif
#ifndef TT30_B_OFFSET
#define TT30_B_OFFSET 0
#endif
#ifndef TT30_C_OFFSET
#define TT30_C_OFFSET 0
#endif

#ifndef TT31_X_OFFSET
#define TT31_X_OFFSET 0
#endif
#ifndef TT31_Y_OFFSET
#define TT31_Y_OFFSET 0
#endif
#ifndef TT31_Z_OFFSET
#define TT31_Z_OFFSET 0
#endif
#ifndef TT31_U_OFFSET
#define TT31_U_OFFSET 0
#endif
#ifndef TT31_V_OFFSET
#define TT31_V_OFFSET 0
#endif
#ifndef TT31_W_OFFSET
#define TT31_W_OFFSET 0
#endif
#ifndef TT31_A_OFFSET
#define TT31_A_OFFSET 0
#endif
#ifndef TT31_B_OFFSET
#define TT31_B_OFFSET 0
#endif
#ifndef TT31_C_OFFSET
#define TT31_C_OFFSET 0
#endif

#ifndef TT32_X_OFFSET
#define TT32_X_OFFSET 0
#endif
#ifndef TT32_Y_OFFSET
#define TT32_Y_OFFSET 0
#endif
#ifndef TT32_Z_OFFSET
#define TT32_Z_OFFSET 0
#endif
#ifndef TT32_U_OFFSET
#define TT32_U_OFFSET 0
#endif
#ifndef TT32_V_OFFSET
#define TT32_V_OFFSET 0
#endif
#ifndef TT32_W_OFFSET
#define TT32_W_OFFSET 0
#endif
#ifndef TT32_A_OFFSET
#define TT32_A_OFFSET 0
#endif
#ifndef TT32_B_OFFSET
#define TT32_B_OFFSET 0
#endif
#ifndef TT32_C_OFFSET
#define TT32_C_OFFSET 0
#endif
