#include "tpl_os.h"
#include "Arduino.h"

#define PIN 13
static unsigned int state = LOW;

void setup()
{
	pinMode(PIN, OUTPUT);
}

TASK(TaskA) //TURN ON
{
    state=HIGH;
    digitalWrite(PIN, state);
    TerminateTask();
}
TASK(TaskB) //TURN OFF
{
    state=LOW;
    digitalWrite(PIN, state);
    TerminateTask();
}
