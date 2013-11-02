#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[40];
int f[40][40][501];
int res;
//select j items from first i items, total cost is k;
int n, m;
int num;

int main()
{
    int sum;
    int t, ti;
    int i, j;
    int p, q;

    while(scanf("%d", &t) == 1){
        for(ti = 0; ti < t; ++ti){
            memset(f, 0, 40 * 40 * 500 * sizeof(int));
            scanf("%d%d", &n, &m);
            for(i = 1; i <= n; ++i){
                scanf("%d", &a[i]);
            }
            sort(&a[1], &a[n + 1]);

            sum = 0;
            for(i = 1; i <= n; ++i){
                sum += a[i];
                if(sum > m){
                    break;
                }
            }
            num = i - 1;
            if(num == 0){
                printf("Sorry, you can't buy anything.\n");
                continue;
            }

            for(i = 1; i <= n; ++i){
                f[i][1][a[i]] = 1;
            }
            for(j = 2; j <= num; ++j){
                for(i = j; i <= n; ++i){
                    for(p = j - 1; p <= i - 1; ++p){
                        for(q = 0; q <= m - a[i]; ++q){
                            if(f[p][j - 1][q] > 0){
                                f[i][j][q + a[i]] += f[p][j - 1][q];
                            }
                        }
                    }
                }
            }

            res = 0;
            for(q = 0; q <= m; ++q){
                for(j = num; j <= n; ++j){
                    res += f[j][num][q];
                }
            }

            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", res, num);
        }
    }

    return 0;
}

