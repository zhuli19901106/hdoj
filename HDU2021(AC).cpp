#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
const int v[6] = {100, 50, 10, 5, 2, 1};
int c[6];

int main()
{
    int i, j;
    int tmp;

    while(scanf("%d", &n) == 1 && n){
        for(i = 0; i < 6; ++i){
            c[i] = 0;
        }
        for(i = 0; i < n; ++i){
            scanf("%d", &tmp);
            for(j = 0; j < 6; ++j){
                c[j] += (tmp / v[j]);
                tmp = tmp % v[j];
            }
        }

        printf("%d\n", c[0] + c[1] + c[2] + c[3] + c[4] + c[5]);
    }

    return 0;
}

