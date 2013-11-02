#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int getsum(int n)
{
    int i;
    int sum;

    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }

    sum = 0;
    for(i = 1; i * i <= n; ++i){
        if(n % i == 0){
            if(i < n / i){
                sum = sum + i + n / i;
            }else{
                sum = sum + i;
            }
        }
    }

    return sum;
}

int main()
{
    int a, b;
    int sa, sb;
    int t, ti;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            scanf("%d%d", &a, &b);
            sa = getsum(a) - a;
            sb = getsum(b) - b;
            if(sa != b || sb != a){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }

    return 0;
}

