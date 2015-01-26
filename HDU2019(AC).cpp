#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int a[105];

int main()
{
	int i;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		a[n++] = m;
		sort(a, a + n);
		
		for(i = 0; i < n; ++i){
			printf((i ? " %d" : "%d"), a[i]);
		}
		printf("\n");
	}

	return 0;
}
