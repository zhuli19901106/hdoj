#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[105];

int myabs(const int &a)
{
	return (a > 0 ? a : -a);
}

bool comparator(int a, int b)
{
	return myabs(a) > myabs(b);
}

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n, comparator);
		
		for(i = 0; i < n; ++i){
			printf((i ? " %d" : "%d"), a[i]);
		}
		printf("\n");
	}

	return 0;
}
