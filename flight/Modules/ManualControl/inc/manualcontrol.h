/**
 ******************************************************************************
 * @addtogroup OpenPilotModules OpenPilot Modules
 * @{
 * @addtogroup ManualControlModule Manual Control Module
 * @{
 *
 * @file       manualcontrol.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      ManualControl module. Handles safety R/C link and flight mode.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H

#include "manualcontrolcommand.h"

typedef enum {FLIGHTMODE_UNDEFINED = 0, FLIGHTMODE_MANUAL = 1, FLIGHTMODE_STABILIZED = 2, FLIGHTMODE_GUIDANCE = 3} flightmode_path;

#define PARSE_FLIGHT_MODE(x) ( \
	(x == FLIGHTSTATUS_FLIGHTMODE_MANUAL) ? FLIGHTMODE_MANUAL : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED1) ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED2) ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED3) ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_VELOCITYCONTROL) ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_POSITIONHOLD) ? FLIGHTMODE_GUIDANCE : FLIGHTMODE_UNDEFINED \
	)

int32_t ManualControlInitialize();


/*
 * These are assumptions we make in the flight code about the order of settings and their consistency between
 * objects.  Please keep this synchronized to the UAVObjects
 */
#define assumptions1 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)      \
)

#define assumptions3 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)     \
)

#define assumptions5 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)     \
)

#define ARMING_CHANNEL_ROLL     0
#define ARMING_CHANNEL_PITCH    1
#define ARMING_CHANNEL_YAW      2

#define assumptions7 ( \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_ROLL) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLRIGHT          -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_ROLL) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHFORWARD       -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_PITCH) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHAFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_PITCH) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWLEFT            -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_YAW) 		&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWRIGHT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_YAW)		\
)

#define assumptions8 ( \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLRIGHT          -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHFORWARD       -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHAFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWLEFT            -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0)	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWRIGHT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0)	\
)

#define assumptions_flightmode ( \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_MANUAL == (int) FLIGHTSTATUS_FLIGHTMODE_MANUAL) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED1 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED1) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED2 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED2) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED3 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED3) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_VELOCITYCONTROL == (int) FLIGHTSTATUS_FLIGHTMODE_VELOCITYCONTROL) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_POSITIONHOLD == (int) FLIGHTSTATUS_FLIGHTMODE_POSITIONHOLD) \
)

#endif // MANUALCONTROL_H
