#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int myabs(int a)
{
	return (a > 0 ? a : -a);
}

int main()
{
	int a[1000];
	int n;
	int t, ti;
	int i;
	int res;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				scanf("%d", &a[i]);
			}
			sort(a, a + n);
			res = 0;
			for(i = 0; i < n; ++i){
				res = res + myabs(a[i] - a[(n - 1) / 2]);
			}

			printf("%d\n", res);
		}
	}

	return 0;
}
