#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int a[21];

int main()
{
	int n;
	int t, ti;

	a[0] = 0;
	a[1] = 1;
	for(n = 2; n <= 20; ++n){
		a[n] = a[n - 1] * 3;
	}
	for(n = 1; n <= 20; ++n){
		++a[n];
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%d\n", a[n]);
		}
	}

	return 0;
}
