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

#define PIN_OUTPUT_TASK_A   1
#define PIN_OUTPUT_TASK_B   2
#define PIN_OUTPUT_TASK_C   3
#define PIN_OUTPUT_RESOURCE 7

// bool resourceUsed = true;
// uint8 resource = 0;

void do_things(int ms, int outputPin, bool stopResource)
{
    unsigned long mul = ms * 198UL; //* 504UL / 3;
    unsigned long i;
    uint8 resourceUsed=1;
    if( stopResource )
    {
        // WaitEvent(heyImHere);
        while(resourceUsed){
            ReceiveMessage(msgDataReceiveUnqueued, &resourceUsed);
        }
        
        resourceUsed=true;
        // ReceiveMessage(msgDataReceiveUnqueued, &resource);
        digitalWrite(PIN_OUTPUT_RESOURCE, HIGH);
    }
    digitalWrite(PIN_OUTPUT_TASK_A, LOW);
    digitalWrite(PIN_OUTPUT_TASK_B, LOW);
    digitalWrite(PIN_OUTPUT_TASK_C, LOW);
    for(i=0; i<mul; i++)
    digitalWrite(outputPin, HIGH);
        millis();
    digitalWrite(outputPin, LOW);
    if( stopResource )
    {
        // resourceUsed=false;
        resourceUsed=0;
        SendMessage(msgDataSend, &resourceUsed);
        digitalWrite(PIN_OUTPUT_RESOURCE, LOW);
    }
}

void setup()
{
    uint8 resourceUsed=0;
	pinMode(PIN_OUTPUT_TASK_A, OUTPUT);
    pinMode(PIN_OUTPUT_TASK_B, OUTPUT);
    pinMode(PIN_OUTPUT_TASK_C, OUTPUT);
    pinMode(PIN_OUTPUT_RESOURCE, OUTPUT);
    SendMessage(msgDataSend, &resourceUsed);
}

TASK(TaskA)
{
    do_things(200,PIN_OUTPUT_TASK_A,true);
    TerminateTask();
}
TASK(TaskB) 
{
    do_things(700,PIN_OUTPUT_TASK_B,false);
    TerminateTask();
}
TASK(TaskC) 
{
    do_things(100,PIN_OUTPUT_TASK_C,false);
    do_things(200,PIN_OUTPUT_TASK_C,true);
    TerminateTask();
}