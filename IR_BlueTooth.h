/*
  IR_BlueTooth.h
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
#ifndef _IR_BLUETOOTH_H_
#define _IR_BLUETOOTH_H_

#include <SoftwareSerial.h>   //Software Serial Port

static void setupBlueToothConnection();
static void CheckOK();
static void sendBlueToothCommand(char command[]);
static void checkBluetoothState(char state);

void blueTooth_Init();      // init bluetooth

// send data to bluetooth, len: data length, dataSend: data buffer
void blueToothSend(INT8U len, INT8U *dataSend); 
// receive data from bluetooth,  dataRev: data buffer    
INT8U blueToothRev(INT8U *dataRev);

#endif
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/