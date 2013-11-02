#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int res, i;
    double v, d, s;

    while(scanf("%lf%lf", &v, &d) == 2){
        s = 0;
        res = 0;
        for(i = 1; ; ++i){
            s += i * d;
            res += i;
            ++res;
            if(v - s <= (i + 1) * d){
                if((v - s) / d == (int)((v - s) / d)){
                    res += (v - s) / d;
                }else{
                    res += (v - s) / d + 1;
                }
                break;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

