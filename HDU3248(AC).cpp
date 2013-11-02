#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a;

    while(scanf("%d", &a) == 1 && a != -1){
        a = (450 - a) % 360;
        if(a % 30){
            printf("Between %d o'clock and %d o'clock\n", a / 30, (a / 30 + 1) % 12);
        }else{
            printf("Exactly %d o'clock\n", a / 30);
        }
    }

    return 0;
}

