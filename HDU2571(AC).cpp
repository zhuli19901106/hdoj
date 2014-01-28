#include <cstdio>
using namespace std;

const int MAXN = 21;
const int MAXM = 1001;
int a[MAXN][MAXM];
int f[MAXN][MAXM];
int n, m;
const int INF = 1000000000;

int main()
{
	int i, j, k;
	int c, ci;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d%d", &n, &m);
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= m; ++j) {
					scanf("%d", &a[i][j]);
					f[i][j] = -INF;
				}
			}

			f[1][1] = a[1][1];
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= m; ++j) {
					if (i < n && f[i + 1][j] < f[i][j] + a[i + 1][j]) {
						f[i + 1][j] = f[i][j] + a[i + 1][j];
					}
					if (j < m && f[i][j + 1] < f[i][j] + a[i][j + 1]) {
						f[i][j + 1] = f[i][j] + a[i][j + 1];
					}
					for (k = 2; j * k <= m; ++k) {
						if (f[i][j * k] < f[i][j] + a[i][j * k]) {
							f[i][j * k] = f[i][j] + a[i][j * k];
						}
					}
				}
			}
			printf("%d\n", f[n][m]);
		}
	}

	return 0;
}