#include "tpl_os.h"
#include "Arduino.h"

#define SIZE_BUFFER 100
#define DISTANCE_BUFFER 20
#define PIN_INPUT A0

#include "bufferArray.h"
#include <stdlib.h>

S buffer;

void setup()
{
    Serial.begin(115200);
	buffer = BUFFERinit(SIZE_BUFFER,DISTANCE_BUFFER);
}

TASK(TaskADC)
{
    BUFFERpush(buffer,map(analogRead(PIN_INPUT), 0, 1023, 0, 255));
    TerminateTask();
}
TASK(TaskPWM) 
{
    int *data = BUFFERmodelHR(buffer);
    int length = howManyPeaks(buffer, findPeak(buffer));
    int i;
    Serial.print("\n");
    for (i=0; i<length; i++)
    {
        Serial.print("HR :"); Serial.print(data[i]); Serial.print(" peak:"); Serial.print(findPeak(buffer)); Serial.print(" peaks:"); Serial.print(length);
    }
    TerminateTask();
}