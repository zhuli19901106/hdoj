#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[10005];
int n;
int ll, rr, mll, mrr;
int sum, msum;

int main()
{
    int i;

    while(scanf("%d", &n) == 1 && n){
        for(i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }

        for(i = 0; i < n; ++i){
            if(a[i] >= 0){
                break;
            }
        }
        if(i == n){
            printf("0 %d %d\n", a[0], a[n - 1]);
            continue;
        }

        msum = -2147483647 - 1;
        sum = 0;
        mll = ll = 0;
        for(i = 0; i < n; ++i){
            sum += a[i];
            if(sum > msum){
                msum = sum;
                mll = ll;
                mrr = i;
            }
            if(sum < 0){
                sum = 0;
                ll = i + 1;
            }
        }

        printf("%d %d %d\n", msum, a[mll], a[mrr]);
    }

    return 0;
}

