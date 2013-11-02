#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double rad;

int main()
{
    while(scanf("%lf", &rad) == 1){
        if(rad >= 0){
            printf("%.2f\n", rad);
        }else{
            printf("%.2f\n", -rad);
        }
    }

    return 0;
}

