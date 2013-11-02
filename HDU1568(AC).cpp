#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[21];

int main()
{
    int i;
    int n;
    double sum, x;

    a[0] = 0;
    a[1] = 1;
    for(i = 2; i <= 20; ++i){
        a[i] = a[i - 1] + a[i - 2];
    }

    while(scanf("%d", &n) == 1){
        if(n <= 20){
            printf("%d\n", a[n]);
            continue;
        }
        sum = n * log10((1.0 + sqrt(5.0)) / 2.0) - log10(5.0) / 2.0;
        x = sum - (int)sum;
        x = pow(10.0, x);
        while(x < 1000.0){
            x *= 10.0;
        }

        printf("%d\n", (int)x);
    }

    return 0;
}

