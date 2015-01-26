#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 122;
int f[MAXN][MAXN][MAXN];
int res[MAXN];

int main()
{
	int n, i, j, k;

	memset(f, 0, MAXN * MAXN * MAXN * sizeof(int));
	for(i = 1; i < MAXN; ++i){
		f[i][1][i] = 1;
	}
	for(i = 2; i < MAXN; ++i){
		for(n = i; n < MAXN; ++n){
			for(j = 1; j <= n - i + 1; ++j){
				for(k = 1; k <= j; ++k){
					f[n][i][j] += f[n - j][i - 1][k];
				}
			}
		}
	}

	for(n = 1; n < MAXN; ++n){
		res[n] = 0;
		for(i = 1; i <= MAXN; ++i){
			for(j = 1; j <= MAXN; ++j){
				res[n] += f[n][i][j];
			}
		}
	}

	while(scanf("%d", &n) == 1){
		printf("%d\n", res[n]);
	}

	return 0;
}
