#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
double sum_c, c;
double sum_p, p;
double sc;

int main()
{
    int i;
    

    while(scanf("%d", &n) == 1){
        sum_c = 0;
        sum_p = 0;
        for(i = 0; i < n; ++i){
            scanf("%lf%lf", &c, &sc);
            if(sc < 0){
                continue;
            }
            sum_c += c;
            if(sc >= 90){
                sum_p += c * 4.0;
            }else if(sc >= 80){
                sum_p += c * 3.0;
            }else if(sc >= 70){
                sum_p += c * 2.0;
            }else if(sc >= 60){
                sum_p += c * 1.0;
            }
        }

        if(sum_c == 0.0){
            printf("-1\n");
        }else{
            printf("%.2f\n", sum_p / sum_c);
        }
    }

    return 0;
}

