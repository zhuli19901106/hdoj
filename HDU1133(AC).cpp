#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int m,n;
int res[MAXN];

void multiply_by(int a[], int n)
{
    int i;

    for(i = 0; i < MAXN; ++i){
        a[i] = a[i] * n;
    }

    for(i = 0; i < MAXN - 1; ++i){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    a[MAXN - 1] %= 10;
}

int main()
{
    int i;
    int ti;

    ti = 0;
    while(scanf("%d%d", &m, &n) == 2 && (m || n)){
        ++ti;
        printf("Test #%d:\n", ti);
        if(m < n){
            printf("0\n");
            continue;
        }
        memset(res, 0, MAXN * sizeof(int));
        res[0] = 1;
        for(i = 1; i <= m + n; ++i){
            if(i == m + 1){
                continue;
            }
            multiply_by(res, i);
        }
        if(n > 0){
            multiply_by(res, m - n + 1);
        }

        i = MAXN - 1;
        while(i >= 1 && res[i] == 0){
            --i;
        }
        while(i >= 0){
            printf("%d", res[i]);
            --i;
        }
        printf("\n");
    }

    return 0;
}

