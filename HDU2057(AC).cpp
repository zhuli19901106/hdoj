#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a, b;

int main()
{
    while(scanf("%I64X%I64X", &a, &b) == 2){
        b = a + b;
        if(b < 0){
            printf("-%I64X\n", -b);
        }else{
            printf("%I64X\n", b);
        }
    }

    return 0;
}

