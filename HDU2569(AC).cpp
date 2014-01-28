#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 40;
	int a[MAXN][3][3];
	int res[MAXN];
	int i;

	memset(res, 0, MAXN * sizeof(int));
	memset(a, 0, MAXN * 3 * 3 * sizeof(int));
	a[2][0][0] = a[2][0][1] = a[2][0][2] = 1;
	a[2][1][0] = a[2][1][1] = a[2][1][2] = 1;
	a[2][2][0] = a[2][2][1] = a[2][2][2] = 1;

	for (i = 3; i < 40; ++i) {
		a[i][0][0] = a[i - 1][0][0] + a[i - 1][1][0] + a[i - 1][2][0];
		a[i][0][1] = a[i - 1][0][0] + a[i - 1][1][0];
		a[i][0][2] = a[i - 1][0][0] + a[i - 1][2][0];
		a[i][1][0] = a[i - 1][0][1] + a[i - 1][1][1];
		a[i][1][1] = a[i - 1][0][1] + a[i - 1][1][1] + a[i - 1][2][1];
		a[i][1][2] = a[i - 1][1][1] + a[i - 1][2][1];
		a[i][2][0] = a[i - 1][0][2] + a[i - 1][2][2];
		a[i][2][1] = a[i - 1][1][2] + a[i - 1][2][2];
		a[i][2][2] = a[i - 1][0][2] + a[i - 1][1][2] + a[i - 1][2][2];
	}

	int j, k;
	res[1] = 3;
	for (i = 2; i < 40; ++i) {
		res[i] = 0;
		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				res[i] += a[i][j][k];
			}
		}
	}

	int c, ci;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d", &i);
			printf("%d\n", res[i]);
		}
	}

	return 0;
}