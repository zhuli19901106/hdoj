#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

__int64 mypow2(int k)
{
    __int64 res;
    int i;

    res = 1;
    for(i = 0; i < k; ++i){
        res = res * 2;
    }

    return res;
}

int main()
{
    int k;
    __int64 a, b;
    __int64 low, up;
    int res;

    while(scanf("%d", &k) == 1){
        scanf("%I64d%I64d", &a, &b);
        if(k == 64){
            up = 0x7fffffffffffffff;
            low = -up - 1;
        }else{
            up = mypow2(k - 1) - 1;
            low = -up - 1;
        }
        if(a == 0 || b == 0){
            res = 0;
        }else if(a > 0){
            if(b > 0){
                if(up - a >= b){
                    res = 0;
                }else{
                    res = 1;
                }
            }else{
                res = 0;
            }
        }else{
            if(b > 0){
                res = 0;
            }else{
                if(low - a <= b){
                    res = 0;
                }else{
                    res = 1;
                }
            }
        }

        if(res){
            printf("Yes\n");
        }else{
            printf("WaHaHa\n");
        }
    }

    return 0;
}

