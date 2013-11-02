#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int n, m;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &n, &m);
            if(n <= m){
                printf("Grass\n");
            }else if(n % (m + 1) == 0){
                printf("Rabbit\n");
            }else{
                printf("Grass\n");
            }
        }
    }

    return 0;
}

