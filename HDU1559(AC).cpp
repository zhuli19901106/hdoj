#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int w, h;
int s, t;
const int MAXN = 1005;
__int64 a[MAXN][MAXN];
__int64 ps[MAXN][MAXN];
__int64 sum[MAXN][MAXN];
__int64 res;

int main()
{
	int i, j;
	int tt, tti;

	while(scanf("%d", &tt) == 1){
		for(tti = 0; tti < tt; ++tti){
			scanf("%d%d%d%d", &w, &h, &s, &t);
			memset(a, 0, MAXN * MAXN * sizeof(__int64));
			memset(ps, 0, MAXN * MAXN * sizeof(__int64));
			memset(sum, 0, MAXN * MAXN * sizeof(__int64));
			for(i = 1; i <= w; ++i){
				for(j = 1; j <= h; ++j){
					scanf("%I64d", &a[i][j]);
				}
			}
			for(i = 1; i <= w; ++i){
				for(j = 1; j <= h; ++j){
					ps[i][j] = ps[i][j - 1] + ps[i - 1][j] + a[i][j] - ps[i - 1][j - 1];
				}
			}
			for(i = s; i <= w; ++i){
				for(j = t; j <= h; ++j){
					sum[i][j] = ps[i][j] + ps[i - s][j - t] - ps[i][j - t] - ps[i - s][j];
				}
			}
			
			res = sum[s][t];
			for(i = s; i <= w; ++i){
				for(j = t; j <= h; ++j){
					if(sum[i][j] > res){
						res = sum[i][j];
					}
				}
			}

			printf("%I64d\n", res);
		}
	}

	return 0;
}
