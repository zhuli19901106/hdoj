#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, res;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            if(n / 150 * 50 < n % 150){
                printf("%d\n", n % 150 - n / 150 * 50);
            }else{
                printf("%d\n", n % 50);
            }
        }
    }

    return 0;
}

