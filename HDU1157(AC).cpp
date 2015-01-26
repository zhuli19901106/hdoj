#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[10005];
int n;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		printf("%d\n", a[(n - 1) / 2]);
	}

	return 0;
}
