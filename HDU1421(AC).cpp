#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 2005;
int f[MAXN][MAXN];
int a[MAXN];
int n, k;

int mymin(const int &a, const int &b)
{
	return (a < b ? a : b);
}

int main()
{
	int i, j;

	while(scanf("%d%d", &n, &k) == 2){
		for(i = 1; i <= n; ++i){
			scanf("%d",&a[i]);
		}
		sort(a + 1, a + n + 1);
		
		f[0][0] = 0;
		for(j = 1; j <= n; ++j){
			f[j][0] = 0;
            for(i = 1; i <= k; ++i){
				if(j - 1 >= 2 * i){
					f[j][i] = mymin(f[j - 1][i], f[j - 2][i - 1] + (a[j] - a[j - 1]) * (a[j] - a[j - 1]));
				}else{
					f[j][i] = f[j - 2][i - 1] + (a[j] - a[j - 1]) * (a[j] - a[j - 1]);
				}
			}
		}
		printf("%d\n", f[n][k]);
	}

	return 0;
}
