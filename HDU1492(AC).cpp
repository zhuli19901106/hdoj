#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    __int64 n;
    int a[4] = {2, 3, 5, 7};
    int c[4];
    int i;

    while(scanf("%I64d", &n) == 1 && n){
        for(i = 0; i < 4; ++i){
            c[i] = 0;
            while(n % a[i] == 0){
                ++c[i];
                n /= a[i];
            }
        }
        printf("%I64d\n", 1LL * (c[0] + 1) * (c[1] + 1) * (c[2] + 1) * (c[3] + 1));
    }

    return 0;
}

