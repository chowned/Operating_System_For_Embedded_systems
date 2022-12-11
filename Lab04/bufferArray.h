#ifndef BUFFER_H_DEFINED
#define BUFFER_H_DEFINED

typedef struct BUFFER *S;

S    BUFFERinit(int maxN);
int  BUFFERempty(S);
int  BUFFERsize(S);
void BUFFERpush(S, int);
int BUFFERshowSum(S);

#endif
