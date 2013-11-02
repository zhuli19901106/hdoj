#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int x1, y1;
int sum1, sum2;

int calc_date(int x, int y)
{
    int i, sum;

    sum = 0;
    for(i = 1; i < x; ++i){
        sum += a[i];
    }
    sum += y;

    return sum;
}

int main()
{
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &x1, &y1);
            sum1 = calc_date(x1, y1);
            sum2 = calc_date(10, 21);
            if(sum1 > sum2){
                printf("What a pity, it has passed!\n");
            }else if(sum1 < sum2){
                printf("%d\n", sum2 - sum1);
            }else{
                printf("It's today!!\n");
            }
        }
    }

    return 0;
}

