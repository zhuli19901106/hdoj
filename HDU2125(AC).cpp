#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m, n;
__int64 a[100][100];
int x1, y1, x2, y2;

void myswap(int &x, int &y)
{
	int t;

	t = x;
	x = y;
	y = t;
}

int main()
{
	int i, j;

	while(scanf("%d%d", &n, &m) == 2){
		memset(a, 0, 100 * 100 * sizeof(__int64));
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		++x1;
		++y1;
		++x2;
		++y2;
		if(x1 == x2){
			if(y1 > y2){
				myswap(x1, x2);
				myswap(y1, y2);
			}
		}else if(y1 == y2){
			if(x1 > x2){
				myswap(x1, x2);
				myswap(y1, y2);
			}
		}

		a[1][1] = 1;
		for(i = 1; i <= m; ++i){
			for(j = 1; j <= n; ++j){
				if(!(x1 == i - 1 && y1 == j && x2 == i && y2 == j)){
					a[i][j] += a[i - 1][j];
				}
				if(!(x1 == i && y1 == j - 1 && x2 == i && y2 == j)){
					a[i][j] += a[i][j - 1];
				}
			}
		}
		printf("%I64d\n", a[m][n]);
	}

	return 0;
}
