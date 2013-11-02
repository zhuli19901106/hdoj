#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int gcd(int x, int y)
{
    while(true){
        if(x >= y){
            if(x % y){
                x = x % y;
            }else{
                return y;
            }
        }else{
            if(y % x){
                y = y % x;
            }else{
                return x;
            }
        }
    }
}

int ext_gcd(int a, int b, int &x, int &y)
{
    int x1, y1;
    int res;

    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }

    res = ext_gcd(b % a, a, x1, y1);
    y = x1;
    x = y1 - b / a * x1;
    return res;
}

int main()
{
    int a, b;
    int x, y;
    int res;

    while(scanf("%d%d", &a, &b) == 2){
        if(gcd(a, b) == 1){
            res = ext_gcd(a, b, x, y);
            while(x < 0){
                x += b;
                y -= a;
            }
            while(x >= b){
                x -= b;
                y += a;
            }
            printf("%d %d\n", x, y);
        }else{
            printf("sorry\n");
        }
    }


    return 0;
}

