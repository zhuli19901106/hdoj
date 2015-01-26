#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int a[1005][3];
	int n;

	memset(a, 0, 1005 * 3 * sizeof(int));
	a[0][0] = 1;
	for(n = 1; n <= 1000; ++n){
		a[n][0] = (a[n - 1][1] + a[n - 1][2]) % 10000;
		a[n][1] = (a[n - 1][2] + a[n - 1][0]) % 10000;
		a[n][2] = (a[n - 1][0] + a[n - 1][1]) % 10000;
	}
	
	while(scanf("%d", &n) == 1 && n){
		printf("%d\n", a[n][0]);
	}

	return 0;
}
