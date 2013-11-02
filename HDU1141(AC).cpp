#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    double res;
    double sum;

    while(scanf("%d", &n) == 1 && n){
        n = (n - 1960) / 10 + 2;
        sum = pow(2.0, n);
        res = 0;
        n = 0;
        while(res < sum){
            res += log(1.0 * (++n)) / log(2.0);
        }
        --n;
        printf("%d\n", n);
    }

    return 0;
}

