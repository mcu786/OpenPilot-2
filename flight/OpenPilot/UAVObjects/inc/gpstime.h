/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup GPSTime GPSTime 
 * @brief Contains the GPS time from @ref GPSModule.  Required to compute the world magnetic model correctly when setting the home location.
 *
 * Autogenerated files and functions for GPSTime Object
 
 * @{ 
 *
 * @file       gpstime.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Implementation of the GPSTime object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: gpstime.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
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

#ifndef GPSTIME_H
#define GPSTIME_H

// Object constants
#define GPSTIME_OBJID 1459613858U
#define GPSTIME_NAME "GPSTime"
#define GPSTIME_METANAME "GPSTimeMeta"
#define GPSTIME_ISSINGLEINST 1
#define GPSTIME_ISSETTINGS 0
#define GPSTIME_NUMBYTES sizeof(GPSTimeData)

// Object access macros
/**
 * @function GPSTimeGet(dataOut)
 * @brief Populate a GPSTimeData object
 * @param[out] dataOut 
 */
#define GPSTimeGet(dataOut) UAVObjGetData(GPSTimeHandle(), dataOut)
#define GPSTimeSet(dataIn) UAVObjSetData(GPSTimeHandle(), dataIn)
#define GPSTimeInstGet(instId, dataOut) UAVObjGetInstanceData(GPSTimeHandle(), instId, dataOut)
#define GPSTimeInstSet(instId, dataIn) UAVObjSetInstanceData(GPSTimeHandle(), instId, dataIn)
#define GPSTimeConnectQueue(queue) UAVObjConnectQueue(GPSTimeHandle(), queue, EV_MASK_ALL_UPDATES)
#define GPSTimeConnectCallback(cb) UAVObjConnectCallback(GPSTimeHandle(), cb, EV_MASK_ALL_UPDATES)
#define GPSTimeCreateInstance() UAVObjCreateInstance(GPSTimeHandle())
#define GPSTimeRequestUpdate() UAVObjRequestUpdate(GPSTimeHandle())
#define GPSTimeRequestInstUpdate(instId) UAVObjRequestInstanceUpdate(GPSTimeHandle(), instId)
#define GPSTimeUpdated() UAVObjUpdated(GPSTimeHandle())
#define GPSTimeInstUpdated(instId) UAVObjUpdated(GPSTimeHandle(), instId)
#define GPSTimeGetMetadata(dataOut) UAVObjGetMetadata(GPSTimeHandle(), dataOut)
#define GPSTimeSetMetadata(dataIn) UAVObjSetMetadata(GPSTimeHandle(), dataIn)
#define GPSTimeReadOnly(dataIn) UAVObjReadOnly(GPSTimeHandle())

// Object data
typedef struct {
    int8_t Month;
    int8_t Day;
    int16_t Year;
    int8_t Hour;
    int8_t Minute;
    int8_t Second;

} __attribute__((packed)) GPSTimeData;

// Field information
// Field Month information
// Field Day information
// Field Year information
// Field Hour information
// Field Minute information
// Field Second information


// Generic interface functions
int32_t GPSTimeInitialize();
UAVObjHandle GPSTimeHandle();

#endif // GPSTIME_H

/**
 * @}
 * @}
 */