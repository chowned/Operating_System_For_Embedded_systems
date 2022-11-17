#include "tpl_os.h"
#include "Arduino.h"
#include <stdlib.h>
#define PIN_INPUT A0
#define PIN_OUTPUT 12
unsigned short int activationTimes=0;
unsigned char* value;
void setup()
{
	pinMode(PIN_OUTPUT, OUTPUT);
    value = (unsigned char*) malloc(8); // paid the price only 1 time
}

TASK(TaskADC)
{
    *value = map(analogRead(PIN_INPUT), 0, 1023, 0, 50);                   // Bucketization of value between 0 (0V) and 50 (5V) -> (resolution 0.1V)
    SendMessage(msgDataSend, value);                                              // send the data to the other task, send the pointer
    TerminateTask();
}
TASK(TaskPWM) 
{
    static unsigned short int dataHere;                                           // static, as it must be persistent among different calls
    if (activationTimes == 0)                                                     // we arrived ad the end of one period
    { ReceiveMessage(msgDataReceiveUnqueued, &dataHere); activationTimes=50; }    // receive the bucket value and restore period
    if(activationTimes --< dataHere){ digitalWrite(PIN_OUTPUT,HIGH); }            // DUTY CYCLE HIGH
    else { digitalWrite(PIN_OUTPUT,LOW); }                                        // DUTY CYCLE LOW
    TerminateTask();
}