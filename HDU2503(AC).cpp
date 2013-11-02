#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
    while(true){
        if(a >= b){
            if(a % b){
                a = a % b;
            }else{
                return b;
            }
        }else{
            if(b % a){
                b = b % a;
            }else{
                return a;
            }
        }
    }
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int t, ti;
    int a, b, c, d;
    int x, y;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d%d%d", &a, &b, &c, &d);
            x = a * d + b * c;
            y = b * d;
            a = gcd(x, y);
            x /= a;
            y /= a;
            printf("%d %d\n", x, y);
        }
    }

    return 0;
}

