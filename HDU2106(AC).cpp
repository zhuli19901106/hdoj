#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, d;
__int64 sum, num, n1, p;

int main()
{
    int i;

    while(scanf("%d", &n) == 1){
        sum = 0;
        for(i = 0; i < n; ++i){
            scanf("%I64d", &num);
            if(getchar() == '('){
                scanf("%d", &d);
                getchar();
            }
            n1 = 0;
            p = 1;
            while(num > 0){
                n1 += (num % 10 * p);
                p *= d;
                num /= 10;
            }
            sum += n1;
        }
        printf("%I64d\n", sum);
    }

    return 0;
}

