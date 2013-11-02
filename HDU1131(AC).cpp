#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 300;
int f[101][MAXN];

void print_digit(const int a[])
{
    int i;

    i = MAXN - 1;
    while(i > 0 && a[i] == 0){
        --i;
    }
    while(i >= 0){
        printf("%d", a[i]);
        --i;
    }
}

int main()
{
    int i, j, k;

    memset(f, 0, 101 * MAXN * sizeof(int));
    f[1][0] = 1;
    for(i = 2; i <= 100; ++i){
        f[i][0] = 1;
        for(j = i + 2; j <= i * 2; ++j){
            k = MAXN - 1;
            while(k >= 0 && f[i][k] == 0){
                --k;
            }
            while(k >= 0){
                f[i][k] *= j;
                --k;
            }
            for(k = 0; k < MAXN - 1; ++k){
                f[i][k + 1] += (f[i][k] / 10);
                f[i][k] %= 10;
            }
            if(f[i][MAXN - 1] > 0){
                printf("OVEFLOW!\n");
                exit(1);
            }
            f[i][MAXN - 1] %= 10;
        }
    }

    while(scanf("%d", &i) == 1 && i){
        print_digit(f[i]);
        printf("\n");
    }

    return 0;
}

