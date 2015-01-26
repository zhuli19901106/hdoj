#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
__int64 a[100001];

int main()
{
	__int64 i;

	a[0] = 0;
	a[1] = 1;
	for(i = 2; i <= 100000; ++i){
		if(i % 3){
			a[i] = a[i - 1] + i;
		}else{
			a[i] = a[i - 1] + i * i * i;
		}
	}

	while(scanf("%d", &n) == 1 && n >= 0){
		printf("%I64d\n", a[n]);
	}

	return 0;
}
