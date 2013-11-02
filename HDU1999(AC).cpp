#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[1001];
int n;

int isprime(int n)
{
    int i;

    for(i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return 0;
        }
    }

    return 1;
}

int main()
{
    int sum;
    int i;
    int ti, t;

    memset(f, 0, 1001 * sizeof(int));
    f[0] = 1;
    for(n = 2; n <= 50000; ++n){
        sum = 1;
        for(i = 2; i * i <= n; ++i){
            if(n % i == 0){
                sum += i;
                if(i != n / i){
                    sum += (n / i);
                }
            }
        }
        if(sum >= 0 && sum <= 1000){
            f[sum] = 1;
        }
    }

    for(n = 3; n <= 1000; ++n){
        if(isprime(n - 1) && f[n] == 0){
            f[n] = 1;
        }
    }

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d", &n);
            if(f[n]){
                printf("no\n");
            }else{
                printf("yes\n");
            }
        }
    }

    return 0;
}

