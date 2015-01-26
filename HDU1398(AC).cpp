#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[301][18];
int n;
int res[301];

int main()
{
	int i, j, k, m;

	memset(a, 0, 301 * 18 * sizeof(int));
	memset(res, 0, 301 * sizeof(int));

	a[0][1] = 1;
	/*
	for(i = 0; i <= 17; ++i){
		a[0][i] = 1;
	}
	*/
	for(i = 1; i <= 300; ++i){
		a[i][1] = 1;
	}
	for(i = 2; i <= 17; ++i){
		for(j = i * i; j <= 300; ++j){
			k = 1;
			while(j - k * i * i >= 0){
				for(m = 1; m <= i - 1; ++m){
					a[j][i] += a[j - k * i * i][m];
				}
				++k;
			}
		}
	}

	for(i = 1; i <= 300; ++i){
		res[i] = 0;
		for(j = 1; j <= 17; ++j){
			res[i] += a[i][j];
		}
	}

	while(scanf("%d", &n) == 1 && n){
		printf("%d\n", res[n]);
	}

	return 0;
}
