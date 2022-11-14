#include "tpl_os.h"
#include "Arduino.h"
#define PIN_INPUT A0
#define PIN_OUTPUT 12
unsigned short int activationTimes=0;
void setup()
{ pinMode(PIN_OUTPUT, OUTPUT); } //Must declare pin as Output

TASK(TaskADC)
{
    unsigned short int value = analogRead(PIN_INPUT);               //Read the analog input
    value = map(value, 0, 1023, 0, 50);                             // Bucketization of value between 0 and 50 (resolution 0.1V)
    SendMessage(msgDataSend, &value);                               // send the data to the other task
    TerminateTask();
}
TASK(TaskPWM) 
{
    static unsigned short int dataHere;                                          // static, as it must be persistent
    if (activationTimes == 0)                                                    // we arrived ad the end of one period
    { ReceiveMessage(msgDataReceiveUnqueued, &dataHere); activationTimes=50; }   // receive the bucket value and restore period
    if(dataHere >-- activationTimes){ digitalWrite(PIN_OUTPUT,HIGH); }           // DUTY CYCLE HIGH
    else { digitalWrite(PIN_OUTPUT,LOW); }                                       // DUTY CYCLE LOW
    TerminateTask();
}
