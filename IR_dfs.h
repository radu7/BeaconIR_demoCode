/*
  IR_dfs.h
  2012 Copyright (c) Seeed Technology Inc.  All right reserved.
 
  Author: Loovee
  2012-8-5
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
*/
#ifndef _IR_DFS_H_
#define _IR_DFS_H_

#include <Arduino.h>

#define DEBUG_MODE              0

#ifndef INT8U
#define INT8U unsigned char
#endif
#ifndef INT8S
#define INT8S signed char
#endif
#ifndef INT16U
#define INT16U unsigned int
#endif
#ifndef INT16S
#define INT16S signed int
#endif
#ifndef INT32U
#define INT32U unsigned long
#endif
#ifndef INT32S
#define INT32S signed long
#endif

// len, start_H, start_L, nshort, nlong, data_len, data[data_len]....
#define D_LEN       0
#define D_STARTH    1
#define D_STARTL    2
#define D_SHORT     3
#define D_LONG      4
#define D_DATALEN   5
#define D_DATA      6

// state machine
#define SM_WAITORDER            0x01
#define SM_STUDY                0x10
#define SM_ORDER                0x20

#endif

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/