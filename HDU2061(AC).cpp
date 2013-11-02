#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
    double sumc, c;
    double g, sumg;
    int t, ti;
    int n, i;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            if(ti > 0){
                printf("\n");
            }

            scanf("%d", &n);
            sumg = 0;
            sumc = 0;
            for(i = 0; i < n; ++i){
                scanf("%*s%lf%lf", &c, &g);
                if(sumg < 0){
                    continue;
                }else if(g < 60){
                    sumg = -1;
                }else{
                    sumg += c * g;
                    sumc += c;
                }
            }

            if(sumg < 0){
                printf("Sorry!\n");
            }else{
                printf("%.2f\n", sumg / sumc);
            }
        }
    }

    return 0;
}

