#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &a, &b);
            if(a % b){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }

    return 0;
}

