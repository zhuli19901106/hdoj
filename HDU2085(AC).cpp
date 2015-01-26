#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 a[34];
__int64 b[34];

int main()
{
	int n;

	a[0] = 1;
	b[0] = 0;
	for(n = 1; n <= 33; ++n){
		a[n] = 3 * a[n - 1] + 2 * b[n - 1];
		b[n] = a[n - 1] + b[n - 1];
	}

	while(scanf("%d", &n) == 1 && n != -1){
		printf("%I64d, %I64d\n", a[n], b[n]);
	}

	return 0;
}
