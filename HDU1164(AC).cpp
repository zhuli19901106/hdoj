#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 65536;
int a[MAXN];
int n;
int p[8000];
int pc;
int f[100][2];
int fc;

int main()
{
    int i, j, k;

    memset(a, 0, MAXN * sizeof(int));
    a[0] = a[1] = 1;
    for(i = 2; i <= (MAXN - 1) / i; ++i){
        if(a[i]){
            continue;
        }
        for(j = i; j <= (MAXN - 1) / i; ++j){
            a[i * j] = 1;
        }
    }

    pc = 0;
    for(i = 0; i < MAXN; ++i){
        a[i] = !a[i];
        if(a[i]){
            p[pc++] = i;
        }
    }
    //printf("PC = %d\n", pc);

    while(scanf("%d", &n) == 1){
        if(n == 0 || n == 1){
            printf("%d\n", n);
            continue;
        }
        i = 0;
        fc = 0;
        while(true){
            if(p[i] > n / p[i]){
                break;
            }else if(n % p[i]){
                ++i;
            }else{
                f[fc][0] = p[i];
                f[fc][1] = 0;
                while(n % p[i] == 0){
                    n /= p[i];
                    ++f[fc][1];
                }
                ++fc;
                ++i;
            }
        }
        if(n > 1){
            f[fc][0] = n;
            f[fc][1] = 1;
            ++fc;
            n = 1;
        }

        k = 0;
        for(i = 0; i < fc; ++i){
            for(j = 0; j < f[i][1]; ++j){
                if(k){
                    printf("*%d", f[i][0]);
                }else{
                    printf("%d", f[i][0]);
                }
                ++k;
            }
        }
        printf("\n");
    }

    return 0;
}

