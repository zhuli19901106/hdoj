#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	__int64 a[36];
	int n;

	a[1] = 2;
	for(n = 2; n <= 35; ++n){
		a[n] = 3 * a[n - 1] + 2;
	}

	while(scanf("%d", &n) == 1){
		printf("%I64d\n", a[n]);
	}

	return 0;
}
