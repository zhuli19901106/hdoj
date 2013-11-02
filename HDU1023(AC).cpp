#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 80;
int a[101][MAXN];
int tmp[MAXN];

void print(const int a[])
{
    int i;

    i = MAXN - 1;
    while(i >= 0 && a[i] == 0){
        --i;
    }
    if(i < 0){
        printf("0");
    }else{
        while(i >= 0){
            printf("%d", a[i]);
            --i;
        }
    }
}

void add(int a[], int b[])
{
    int i;

    for(i = 0; i < MAXN; ++i){
        a[i] = a[i] + b[i];
    }
    
    for(i = 0; i < MAXN - 1; ++i){
        a[i + 1] += (a[i] / 10);
        a[i] %= 10;
    }
    a[MAXN - 1] %= 10;
}

void multiply(int a[], int b[], int c[])
{
    int i, j;

    memset(a, 0, MAXN * sizeof(int));
    for(i = 0; i < MAXN; ++i){
        for(j = 0; i + j < MAXN; ++j){
            if(b[i] && c[j]){
                a[i + j] += (b[i] * c[j]);
            }
        }
    }

    for(i = 0; i < MAXN - 1; ++i){
        a[i + 1] += (a[i] / 10);
        a[i] %= 10;
    }
    a[MAXN - 1] %= 10;
}

int main()
{
    int i, j;

    memset(a, 0, 101 * MAXN * sizeof(int));
    a[0][0] = 1;
    a[1][0] = 1;
    for(i = 2; i <= 100; ++i){
        for(j = 0; j <= i - 1; ++j){
            multiply(tmp, a[j], a[i - 1 - j]);
            add(a[i], tmp);
        }
    }

    while(scanf("%d", &i) == 1){
        print(a[i]);
        printf("\n");
    }

    return 0;
}

