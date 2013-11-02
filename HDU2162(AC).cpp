#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int sum;
    int n;
    int tmp;
    int i;

    i = 0;
    while(scanf("%d", &n) == 1 && n > 0){
        ++i;
        sum = 0;
        while(n--){
            scanf("%d", &tmp);
            sum += tmp;
        }
        printf("Sum of #%d is %d\n", i, sum);
    }

    return 0;
}

