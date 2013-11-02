#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int t, ti;
    int n, i, j;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            for(i = 0; i < 3 * n; ++i){
                for(j = 0; j < n; ++j){
                    printf("HDU");
                }
                printf("\n");
            }
        }
    }

    return 0;
}

