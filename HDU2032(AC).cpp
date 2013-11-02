#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[31][31];
int n;

int main()
{
    int i, j;

    memset(a, 0, 31 * 31 * sizeof(int));
    a[1][1] = 1;
    for(i = 2; i <= 30; ++i){
        a[i][1] = 1;
        for(j = 2; j <= i; ++j){
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    while(scanf("%d", &n) == 1){
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= i; ++j){
                printf((j > 1 ? " %d" : "%d"), a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

