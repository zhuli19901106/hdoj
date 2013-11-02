#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int t, ti;
    int n, i;
    int sum;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            sum = 1;
            for(i = 2; i <= n / i; ++i){
                if(n % i == 0){
                    sum += i;
                    if(i != n / i){
                        sum += n / i;
                    }
                }
            }
            printf("%d\n", sum);
        }
    }

    return 0;
}

