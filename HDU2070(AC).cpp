#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	__int64 a[51];
	int i;

	a[0] = 0;
	a[1] = 1;
	for(i = 2; i <= 50; ++i){
		a[i] = a[i - 1] + a[i - 2];
	}

	while(scanf("%d", &i) == 1 && i != -1){
		printf("%I64d\n", a[i]);
	}

	return 0;
}
