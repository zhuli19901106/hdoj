#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[1000001];
int p[80000];
int pc;

inline int mymin(const int &a, const int &b)
{
    return (a < b ? a : b);
}

int main()
{
    int i, j;

    memset(b, 0, 1000001 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i < 10000001 / i; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; j < 1000001 / i; ++j){
            b[i * j] = 1;
        }
    }

    pc = 0;
    for(i = 0; i < 1000001; ++i){
        b[i] = !b[i];
        if(b[i]){
            p[pc++] = i;
        }
    }

    memset(b, 0, 1000001 * sizeof(int));
    for(i = pc - 1; i >= 0; --i){
        for(j = 1000000 / p[i]; j >= 1; --j){
            if(!b[p[i] * j]){
                b[p[i] * j] = i + 1;
            }
        }
    }

    while(scanf("%d", &i) == 1){
        printf("%d\n", b[i]);
    }

    return 0;
}

