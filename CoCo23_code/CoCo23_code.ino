#include <VL6180X.h>
#include <Wire.h>
#include <EEPROM.h>
#include "pin_declare.h"
#include "piccolaZlgoVariables.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "motorMoves.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"
#include "piccolaMoves.h"
#include "piccolaZlgo.h"
#include "piccolaMazeSolve.h"

void setup()
{   stbyHigh();
    tofSetup();
    motorDiver();
    motorInterrupt();
    pinMode(buzzer, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCL2), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR2), countRightOut1, RISING);
    Serial2.begin(9600);
}


void loop()
{
    delay(1000);
    searchStates();
    //eepromClear();
}
