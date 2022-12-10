#include "bufferArray.h"
#include <stdlib.h>

struct BUFFER {
  int *data;
  int n;
  int maxSize;
};

S BUFFERinit(int maxSize) {
  S s = malloc(sizeof *s);
  s->data = malloc(sizeof(int) * maxSize);
  s->n = 0;
  s->maxSize = maxSize;
  return s;
}

int BUFFERempty(S s) { return s->n == 0; }

int BUFFERsize(S s) { return s->maxSize; }

void BUFFERpush(S s, int dataReceived) {
  s->data[s->n] = dataReceived;
  (s->n)++;
  if (s->n == s->maxSize) {
    s->n = 0;
  }
}

int BUFFERshowSum(S s) {
  int sum = 0, i;
  for (i = 0; i < s->maxSize; i++) {
    sum += s->data[i];
  }

  return sum;
}