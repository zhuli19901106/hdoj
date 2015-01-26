#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int a[40];
int main()
{
	int i, n;

	memset(a, 0, 40 * sizeof(long long int));
	a[0] = 1;
	a[2] = 3;
	for(i = 4; i <= 30; i += 2){
		a[i] = 4 * a[i - 2] - a[i - 4];
	}

	while(scanf("%d", &n) == 1 && n != -1){
		printf("%lld\n", a[n]);
	}

	return 0;
}
