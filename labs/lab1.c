#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 500
#define MAX_FLIGHTNO 16



typedef struct {
    char flightNo[MAX_FLIGHTNO]; 
    int chainId;
    int  schedDepMin;            
} Flight;

typedef struct 
{
    int chainId;
    char flightNo[MAX_FLIGHTNO];
    int delay;
}Delay;

static int parseTime(const char *hhmm) {
    int h, m;
    if (sscanf(hhmm, "%d:%d", &h, &m) != 2) return -1;
    if (h < 0 || h > 23 || m < 0 || m > 59) return -1;
    return h * 60 + m;
}

static void formatTime(int minutes, char out[6]) {
    if (minutes < 0) minutes = 0;
    int h = (minutes / 60) % 24, m = minutes % 60;
    sprintf(out, "%02d:%02d", h, m);
}

static int cmpByDepThenFlightNo(const void *A, const void *B) {
    const Flight *a = (const Flight*)A, *b = (const Flight*)B;
    if (a->chainId==b->chainId){
        if (a->schedDepMin != b->schedDepMin) return a->schedDepMin - b->schedDepMin;
        return strcmp(a->flightNo, b->flightNo); /* eşit saatlerde deterministik sıra */
    }
    else 
    {
        return a->chainId-b->chainId;
    }
}


int main()
{
    int N;
    Delay delay1;

    if (scanf("%d", &N) != 1 || N <= 0 || N > MAXN) {
        printf("ERROR: N must be 1..%d\n", MAXN);
        return 1;
    }

    Flight f[MAXN];
        for (int i = 0; i < N; i++) {
        char t[6];
        if (scanf("%15s %d %5s", f[i].flightNo,&f[i].chainId,t) != 3) {
            printf("ERROR: bad input at line %d\n", i+1);
            return 1;
        }
        f[i].schedDepMin = parseTime(t);
        if (f[i].schedDepMin < 0) {
            printf("ERROR: bad time at line %d\n", i+1);
            return 1;
        }
    }
    scanf("%d %15s %d",&delay1.chainId,delay1.flightNo,&delay1.delay);
    qsort(f, N, sizeof(Flight), cmpByDepThenFlightNo);
    int a=0;
    for (;a<N;a++)
    {
        if (f[a].chainId==delay1.chainId && (strcmp(f[a].flightNo,delay1.flightNo)==0))
        {
            while (f[a].chainId==delay1.chainId)
            {
                f[a].schedDepMin+=delay1.delay;
                a++;
            }
        }
    }
     for (int i = 0; i < N; i++) 
    {
        char hhmm[6];
        formatTime(f[i].schedDepMin, hhmm);
        printf("%s %d %s\n",f[i].flightNo ,f[i].chainId,hhmm);
    }
    return 0;
}
