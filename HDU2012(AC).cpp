#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int x, y;

int isprime(int n)
{
    int i;

    if(n <= 1){
        return 0;
    }else{
        for(i = 2; i * i <= n; ++i){
            if(n % i == 0){
                return 0;
            }
        }

        return 1;
    }
}

int main()
{
    int i;

    while(scanf("%d%d", &x, &y) == 2 && (x || y)){
        for(i = x; i <= y; ++i){
            if(!isprime(i * i +    i + 41)){
                break;
            }
        }
        if(i == y + 1){
            printf("OK\n");
        }else{
            printf("Sorry\n");
        }
    }

    return 0;
}

