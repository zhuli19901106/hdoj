#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int sum[21];
int res[21];

int main()
{
	int i;
	int t, ti, n;

	res[1] = sum[1] = 1;
	for(i = 2; i <= 20; ++i){
		res[i] = (1 << (i - 1)) + sum[i - 1];
		sum[i] = sum[i - 1] + res[i];
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%d\n", res[n]);
		}
	}

	return 0;
}
