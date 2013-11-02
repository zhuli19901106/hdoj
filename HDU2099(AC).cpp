#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b;

int main()
{
    int i;
    int count;

    while(scanf("%d%d", &a, &b) == 2 && (a || b)){
        count = 0;
        for(i = 0; i < 100; ++i){
            if(!((a * 100 + i) % b)){
                printf((count++ ? " %02d" : "%02d"), i);
            }
        }
        printf("\n");
    }

    return 0;
}

