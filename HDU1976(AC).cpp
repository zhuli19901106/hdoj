#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    __int64 a, b, c, d, e, f;
    __int64 n1, n2;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%I64d%I64d%I64d", &a, &b, &c);
            scanf("%I64d%I64d%I64d", &d, &e, &f);
            n1 = a * 1001 * 1001 + b * 1001 + c;
            n2 = d * 1001 * 1001 + e * 1001 + f;
            if(n1 > n2){
                printf("First\n");
            }else if(n1 < n2){
                printf("Second\n");
            }else{
                printf("Same\n");
            }
        }
    }

    return 0;
}

