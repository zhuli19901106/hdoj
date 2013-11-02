#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int s10, s16, s12;

int main()
{
    int n0;

    while(scanf("%d", &n) == 1 && n){
        s10 = 0;
        n0 = n;
        while(n){
            s10 += n % 10;
            n /= 10;
        }
        n = n0;
        s12 = 0;
        n0 = n;
        while(n){
            s12 += n % 12;
            n /= 12;
        }
        n = n0;
        s16 = 0;
        n0 = n;
        while(n){
            s16 += n % 16;
            n /= 16;
        }
        n = n0;

        if(s10 == s12 && s12 == s16){
            printf("%d is a Sky Number.\n", n);
        }else{
            printf("%d is not a Sky Number.\n", n);
        }
    }

    return 0;
}

