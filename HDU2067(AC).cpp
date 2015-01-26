#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 a[36][36];
__int64 res[36];

int main()
{
	int i, j;

	memset(a, 0, 36 * 36 * sizeof(__int64));
	a[0][0] = 1;
	res[0] = 1;
	for(i = 1; i < 36; ++i){
		a[i][0] = a[i - 1][0];
		for(j = 1; j < i; ++j){
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
		a[i][i] = a[i][i - 1];
		res[i] = 2 * a[i][i];
	}

	i = 0;
	while(scanf("%d", &j) == 1 && j != -1){
		++i;
		printf("%d %d %I64d\n", i, j, res[j]);
	}

	return 0;
}
