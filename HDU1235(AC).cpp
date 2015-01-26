#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int a[101];
	int n, x;
	int i;

	while(scanf("%d", &n) == 1 && n){
		memset(a, 0, 101 * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%d", &x);
			++a[x];
		}
		scanf("%d", &x);
		printf("%d\n", a[x]);
	}

	return 0;
}
