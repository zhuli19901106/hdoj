#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[101];
int n;

int main()
{
    int i;
    int mini;

    while(scanf("%d", &n) == 1 && n){
        for(i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        mini = 0;
        for(i = 1; i < n; ++i){
            if(a[i] < a[mini]){
                mini = i;
            }
        }
        i = a[0];
        a[0] = a[mini];
        a[mini] = i;
        for(i = 0; i < n; ++i){
            printf((i ? " %d" : "%d"), a[i]);
        }
        printf("\n");
    }

    return 0;
}

