#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[100001];

int main()
{
	int i, j;

	memset(a, 0, 100001 * sizeof(int));
	for(i = 1; i <= 100000; ++i){
		for(j = 1; 100000 / j >= i; ++j){
			a[i * j] = !a[i * j];
		}
	}

	while(scanf("%d", &i) == 1){
		printf("%d\n", a[i]);
	}

	return 0;
}
