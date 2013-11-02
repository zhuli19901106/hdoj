#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b;
    int rt;

    while(scanf("%d%d", &a, &b) == 2 && (a || b)){
        if(a * a - 4 * b >= 0){
            rt = (int)sqrt(1.0 * a * a - 4 * b);
            if(rt * rt == a * a - 4 * b && (rt + a) % 2 == 0){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }else{
            printf("No\n");
        }
    }

    return 0;
}

