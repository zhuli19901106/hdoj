#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[50001];
int p[10001];
int f[500][2];
int fc;
int pc;

int main()
{
    int i, j;
    int t, ti;
    int n;

    memset(b, 0, 50001 * sizeof(int));
    memset(p, 0, 10001 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i * i <= 50000; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; i * j <= 50000; ++j){
            b[i * j] = 1;
        }
    }

    pc = 0;
    for(i = 0; i <= 50000; ++i){
        b[i] = !b[i];
        if(b[i]){
            p[pc++] = i;
        }
    }

    scanf("%d", &t);
    for(ti = 1; ti <= t; ++ti){
        scanf("%d", &n);
        printf("Scenario #%d:\n", ti);
        if(n == 1){
            printf("1\n\n");
            continue;
        }
        memset(f, 0, 500 * 2 * sizeof(int));
        fc = 0;
        i = 2;
        while(true){
            if(n % i == 0){
                f[fc][0] = i;
                f[fc][1] = 0;
                while(n % i == 0){
                    n = n / i;
                    ++f[fc][1];
                }
                ++fc;
                ++i;
            }else{
                ++i;
            }
            if(i * i > n){
                break;
            }
        }
        if(n > 1){
            f[fc][0] = n;
            f[fc][1] = 1;
            ++fc;
        }

        n = 1;
        for(i = 0; i < fc; ++i){
            f[i][1] = f[i][1] * 2;
            n = n * (f[i][1] + 1);
        }
        n = (n + 1) / 2;
        printf("%d\n\n", n);
    }

    return 0;
}

