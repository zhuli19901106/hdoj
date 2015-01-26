#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

double a[21];
double b[21];

int main()
{
	int n;
	int m, mi;

	b[1] = 1;
	b[2] = 2;
	b[3] = 6;
	for(n = 4; n <= 20; ++n){
		b[n] = (n - 1) * (b[n - 1] + b[n - 2]);
	}

	a[1] = 0;
	a[2] = 1;
	a[3] = 2;
	for(n = 4; n <= 20; ++n){
		a[n] = (n - 1) * (a[n - 1] + a[n - 2]);
	}

	while(scanf("%d", &m) == 1){
		for(mi = 0; mi < m; ++mi){
			scanf("%d", &n);
			printf("%.2f%%\n", a[n] / b[n] * 100);
		}
	}

	return 0;
}
