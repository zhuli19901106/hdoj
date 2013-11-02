#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m, n;
int maxi, maxa, maxv;

int main()
{
    int i;
    int mn;
    int tmp;

    while(scanf("%d%d", &m, &n) == 2){
        mn = m * n;
        maxi = -1;
        maxa = maxv = 0;
        for(i = 0; i < mn; ++i){
            scanf("%d", &tmp);
            if(tmp < -2147483647){
                continue;
            }else if((tmp > 0 ? tmp : -tmp) > maxa){
                maxi = i;
                maxa = (tmp > 0 ? tmp : -tmp);
                maxv = tmp;
            }
        }

        printf("%d %d %d\n", maxi / n + 1, maxi % n + 1, maxv);
    }

    return 0;
}

