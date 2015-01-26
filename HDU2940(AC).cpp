#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 150;
int f[101][MAXN];
int res[101];

int main()
{
	int i, j;

	memset(f, 0, 101 * MAXN * sizeof(int));
	memset(res, 0, 101 * sizeof(int));
	f[0][0] = 1;
	for(i = 1; i <= 100; ++i){
		for(j = 0; j < MAXN; ++j){
			f[i][j] = f[i - 1][j] * i;
		}

		for(j = 0; j < MAXN - 1; ++j){
			f[i][j + 1] += (f[i][j] / 16);
			f[i][j] %= 16;
		}
		f[i][MAXN - 1] %= 16;
		if(f[i][MAXN - 1] > 0){
			printf("Big Integer Overflow!\n");
			exit(1);
		}
	}

	memset(res, 0, 101 * sizeof(int));
	for(i = 0; i < 101; ++i){
		j = MAXN - 1;
		while(j > 0 && f[i][j] == 0){
			--j;
		}
		while(j >= 0){
			if(f[i][j] == 0){
				++res[i];
			}
			--j;
		}
	}

	while(scanf("%d", &i) == 1 && i >= 0){
		printf("%d\n", res[i]);
	}

	return 0;
}
