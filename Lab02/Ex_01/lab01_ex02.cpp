#include "tpl_os.h"
#include "Arduino.h"

#define PIN_INPUT A0
#define PIN_OUTPUT 12

// unsigned short int *value;
unsigned short int activationTimes=50;

void setup()
{
	pinMode(PIN_OUTPUT, OUTPUT);
}

TASK(TaskADC) //TURN ON
{
    unsigned short int value = analogRead(PIN_INPUT);
    value = map(value, 0, 1023, 0, 50);
    SendMessage(msgDataSend, &value);
    TerminateTask();
}
TASK(TaskPWM) //TURN OFF
{
    static unsigned short int dataHere;
    if (activationTimes == 50)
    {
        ReceiveMessage(msgDataReceiveUnqueued, &dataHere);
        activationTimes=0;
    }
    if(activationTimes <= dataHere){
        digitalWrite(PIN_OUTPUT,HIGH);
    }
    else
    {
        digitalWrite(PIN_OUTPUT,LOW);
    }
    activationTimes++;
    TerminateTask();
}
