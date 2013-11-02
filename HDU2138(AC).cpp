#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[50000];
int p[20000];
int pc;

int main()
{
    int n, tmp;
    int res, i, j;

    memset(b, 0, 50000 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i * i < 50000; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; i * j < 50000; ++j){
            b[i * j] = 1;
        }
    }
    
    pc = 0;
    for(i = 0; i < 50000; ++i){
        b[i] = !b[i];
        if(b[i]){
            p[pc++] = i;
        }
    }

    while(scanf("%d", &n) == 1){
        res = 0;
        for(i = 0; i < n; ++i){
            scanf("%d", &tmp);
            j = 0;
            while(p[j] <= tmp / p[j]){
                if(tmp % p[j] == 0){
                    break;
                }else{
                    ++j;
                }
            }
            if(p[j] > tmp / p[j]){
                ++res;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

