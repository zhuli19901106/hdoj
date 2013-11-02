#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10001;
int b[MAXN];

int main()
{
    int i, j;
    int n;

    memset(b, 0, 10001 * sizeof(int));
    b[0] = b[1] = 1;
    for(i = 2; i <= (MAXN - 1) / i; ++i){
        if(b[i]){
            continue;
        }
        for(j = i; j <= (MAXN - 1) / i; ++j){
            b[i * j] = 1;
        }
    }

    for(i = 0; i < MAXN; ++i){
        b[i] = !b[i];
    }

    while(scanf("%d", &n) == 1){
        for(i = n / 2; !(b[i] && b[n - i]); --i){
            ;
        }
        printf("%d %d\n", i, n - i);
    }

    return 0;
}

