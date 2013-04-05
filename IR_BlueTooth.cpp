/*
  IR_BlueTooth.cpp
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
#include "IR_dfs.h"
#include "IR_BlueTooth.h"
#define RxD A4          // 6
#define TxD A5          // 7

SoftwareSerial blueToothSerial(RxD,TxD);

void blueTooth_Init()
{
    blueToothSerial.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
    delay(500);
    setupBlueToothConnection();
}

// SEND
void blueToothSend(INT8U len, INT8U *dataSend)
{
    // data head
    blueToothSerial.write(0x53);
    blueToothSerial.write(0x31);
    blueToothSerial.write(0x30);
    for(int i = 0; i<len; i++)
    {
        blueToothSerial.write(dataSend[i]);
    }
    // data tail
    blueToothSerial.write(0x5f);
    blueToothSerial.write(0x45);
}

// REV
INT8U blueToothRev(INT8U *dataRev)
{
    int count = 0;
    while(1)
    {
        if(blueToothSerial.available())
        {
            dataRev[count++] = (INT8U)blueToothSerial.read();
        }
        else
        {
            break;
        }
    }

    return count;
}

static void setupBlueToothConnection()
{
    sendBlueToothCommand("\r\n+STWMOD=0\r\n");
    CheckOK();
    sendBlueToothCommand("\r\n+STNA=Fuck_2bk\r\n");
    CheckOK();
    sendBlueToothCommand("\r\n+STAUTO=0\r\n");
    CheckOK();
    sendBlueToothCommand("\r\n+STOAUT=1\r\n");
    CheckOK();
    sendBlueToothCommand("\r\n +STPIN=0000\r\n");
    checkBluetoothState('1');
    sendBlueToothCommand("\r\n+INQ=1\r\n");
    checkBluetoothState('4');
}

//Checks if the response "OK" is received
static void CheckOK()
{
    char a,b;
    while(1)
    {
        if(blueToothSerial.available())
        {
            a = blueToothSerial.read();
            if('O' == a)
            {
                // Wait for next character K. available() is required in some cases, as K is not immediately available.
                while(blueToothSerial.available())
                {
                    b = blueToothSerial.read();
                    break;
                }
                if('K' == b)
                {
                    break;
                }
            }
        }
    }
}

static void sendBlueToothCommand(char command[])
{
    blueToothSerial.print(command);
}

static void checkBluetoothState(char state)
{
    unsigned char temp;
    while(1)  {
        while(!blueToothSerial.available());
        temp=blueToothSerial.read();
        if(temp=='+')  {
            while(temp!=state)  {
                if(blueToothSerial.available())
                temp=blueToothSerial.read();
            }
            if(temp==state)  {
                break;
            }
        }
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/