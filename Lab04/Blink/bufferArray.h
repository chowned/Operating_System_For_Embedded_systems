#ifndef BUFFER_H_DEFINED
#define BUFFER_H_DEFINED

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BUFFER *S;

S    BUFFERinit(int maxSize, int distanceData);
int  BUFFERempty(S);
int  BUFFERsize(S);
void BUFFERpush(S, int);
int BUFFERshowSum(S);
int* BUFFERmodelHR(S);

#ifdef __cplusplus
}
#endif

#endif
