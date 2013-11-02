#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 350;

int a0[2][MAXN];
int a1[2][MAXN];
int a00[2][MAXN];
int a01[2][MAXN];
int a10[2][MAXN];
int a11[2][MAXN];
int ans[1001][MAXN];

void copy(int a[], int b[], int len)
{
    int i;
    
    for(i = 0; i < len; ++i){
        a[i] = b[i];
    }
}

void add(int a[], int b[], int c[], int len)
{
    int i;
    
    for(i = 0; i < len; ++i){
        a[i] = b[i] + c[i];
    }
    for(i = 0; i < len - 1; ++i){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    a[i] %= 10;
}

void print(int a[], int len)
{
    int i;
    
    i = len - 1;
    while(i >= 0 && a[i] == 0){
        --i;
    }
    if(i == -1){
        printf("0");
    }else{
        while(i >= 0){
            printf("%d", a[i]);
            --i;
        }
    }
}

int main()
{
    int n;
    int f;
    
    f = 0;
    memset(a0, 0, 2 * MAXN * sizeof(int));
    memset(a1, 0, 2 * MAXN * sizeof(int));
    memset(a00, 0, 2 * MAXN * sizeof(int));
    memset(a01, 0, 2 * MAXN * sizeof(int));
    memset(a10, 0, 2 * MAXN * sizeof(int));
    memset(a11, 0, 2 * MAXN * sizeof(int));
    memset(ans, 0, 1001 * MAXN * sizeof(int));
    a0[f][0] = 1;
    a1[f][0] = 1;
    a00[f][0] = 0;
    a01[f][0] = 1;
    a10[f][0] = 0;
    a11[f][0] = 0;
    for(n = 2; n <= 1000; ++n){
        add(a0[!f], a0[f], a1[f], MAXN);
        add(a1[!f], a0[f], a1[f], MAXN);
        copy(a00[!f], a01[f], MAXN);
        add(a01[!f], a1[f], a00[f], MAXN);
        add(a10[!f], a0[f], a11[f], MAXN);
        copy(a11[!f], a10[f], MAXN);
        f = !f;
        copy(ans[n], a00[f], MAXN);
    }
    
    while(true){
        if(scanf("%d", &n) != 1){
            break;
        }else if(n == 1){
            printf("0\n");
        }else{
            print(ans[n], MAXN);
            printf("\n");
        }
    }
    
    return 0;
}

