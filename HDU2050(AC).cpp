#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[10001];

int main()
{
	int n;
	int t, ti;

	a[0] = 1;
	a[1] = 2;
	for(n = 2; n <= 10000; ++n){
		a[n] = 2 * (2 * (n - 1) - 1) + 3 + a[n - 1];
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%I64d\n", a[n]);
		}
	}

	return 0;
}
