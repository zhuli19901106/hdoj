#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m, n;
__int64 s1, s2;

int main()
{
    int i;

    while(scanf("%d%d", &m, &n) == 2){
        if(m > n){
            swap(m, n);
        }
        s1 = 0;
        s2 = 0;
        for(i = m; i <= n; ++i){
            if(i % 2){
                s2 += (i * i * i);
            }else{
                s1 += (i * i);
            }
        }

        printf("%I64d %I64d\n", s1, s2);
    }

    return 0;
}

