#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
const int MAXN = 5005;
const LL INF = 0x7fffffffffffffffLL;
LL a[MAXN];
LL f[2][MAXN];
int flag, fflag;
int n, k;

int main()
{
	int t, ti;
	int i, j;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			memset(a, 0, MAXN * sizeof(LL));
			memset(a, 0, 2 * MAXN * sizeof(LL));
			scanf("%d%d", &k, &n);
			for(i = 1; i <= n; ++i){
				scanf("%lld", &a[i]);
			}
			k += 8;

			memset(f, 0, 2 * MAXN * sizeof(LL));
			for(i = 1; i <= k; ++i){
				j = 2 * i;
				f[1][j] = f[0][j - 2] + (a[j] - a[j - 1]) * (a[j] - a[j - 1]);

				for(++j; j < n - (k - i) * 3; ++j){
					f[1][j] = min(f[1][j - 1], f[0][j - 2] + (a[j] - a[j - 1]) * (a[j] - a[j - 1]));
				}
				f[1][j] = f[1][j - 1];

				memcpy(f[0], f[1], MAXN * sizeof(LL));
			}

 			printf("%lld\n", f[0][n]);
		}
	}

	return 0;
}
