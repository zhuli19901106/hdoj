#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[700], sum, s;
int n;
int res;

bool comparator(const __int64 &a, const __int64 &b)
{
    return a > b;
}

int main()
{
    int i;

    while(scanf("%I64d%d", &sum, &n) == 2){
        for(i = 0; i < n; ++i){
            scanf("%I64d", &a[i]);
        }
        sort(a, a + n, comparator);
        s = 0;
        for(i = 0; i < n; ++i){
            s += a[i];
            if(s >= sum){
                break;
            }
        }

        if(i < n){
            printf("%d\n", i + 1);
        }else{
            printf("impossible\n");
        }
    }

    return 0;
}

