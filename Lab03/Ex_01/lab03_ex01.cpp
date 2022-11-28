/*

WARNING: 
This code is LICENSED. It is being used in the AA 2022-2023 by me and my team member. 
This code is public but it doesn't mean you can take it and send it as yours.
Please, provide your code and your ideas for this course, you may take inspirations from this code.
Any actions that will harm our group can and will be legally persecuted.
As this code is on github with a timestamp, even if you copy this code and deliver before my team, you will take an action against my license
which is legally registered on github. 

# Author: Gaetano Salvatore Falco

*/
#include "tpl_os.h"
#include "Arduino.h"
#include <stdlib.h>

#define PIN_OUTPUT_TASK_A 1
#define PIN_OUTPUT_TASK_B 2
#define PIN_OUTPUT_TASK_C 3

void do_things(int ms, int outputPin)
{
    unsigned long mul = ms * 155UL; //* 504UL / 3;
    unsigned long i;
    for(i=0; i<mul; i++)
        digitalWrite(outputPin, HIGH);
        millis();
    digitalWrite(outputPin, LOW);
}

void cleanOutput()
{
    digitalWrite(PIN_OUTPUT_TASK_A, LOW);
    digitalWrite(PIN_OUTPUT_TASK_B, LOW);
    digitalWrite(PIN_OUTPUT_TASK_C, LOW);
}

void setup()
{
	pinMode(PIN_OUTPUT_TASK_A, OUTPUT);
    pinMode(PIN_OUTPUT_TASK_B, OUTPUT);
    pinMode(PIN_OUTPUT_TASK_C, OUTPUT);
}

TASK(TaskA)
{
    // cleanOutput();
    do_things(200,PIN_OUTPUT_TASK_A);
    TerminateTask();
}
TASK(TaskB) 
{
    // cleanOutput();
    do_things(700,PIN_OUTPUT_TASK_B);
    TerminateTask();
}
TASK(TaskC) 
{
    // cleanOutput();
    do_things(300,PIN_OUTPUT_TASK_C);
    TerminateTask();
}