#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	__int64 a[21];
	int i;

	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	for(i = 3; i <= 20; ++i){
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	}

	while(scanf("%d", &i) == 1){
		printf("%I64d\n", a[i]);
	}

	return 0;
}
