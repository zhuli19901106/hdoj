#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int a, b, c;
    int t, ti;
    int i;
    
    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d%d", &a, &b, &c);
            for(i = 1000; i <= 9999; ++i){
                if(i % a == 0 && (i + 1) % b == 0 && (i + 2) % c == 0){
                    printf("%d\n", i);
                    break;
                }
            }
            if(i > 9999){
                printf("Impossible\n");
            }
        }
    }

    return 0;
}

