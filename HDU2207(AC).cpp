#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int res[33];

int main()
{
    int i;

    while(scanf("%d", &n) == 1){
        memset(res, 0, 33 * sizeof(int));
        n += 2;
        m = 0;
        while(n){
            ++m;
            n /= 2;
        }
        for(i = 1; i <= 32 - m; ++i){
            res[i] = 1;
        }
        m = 0;
        for(i = 1; i <= 32; ++i){
            if(i % 8 == 0){
                m = m * 2 + res[i];
                printf("%d", m);
                m = 0;
                if(i != 32){
                    printf(".");
                }
            }else{
                m = m * 2 + res[i];
            }
        }
        printf("\n");
    }

    return 0;
}

