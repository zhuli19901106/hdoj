#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[60];

int main()
{
	int i;

	memset(a, 0, 60 * sizeof(int));
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	for(i = 3; i < 55; ++i){
		a[i] = a[i - 1] + a[i - 3];
	}
	
	while(scanf("%d", &n) == 1 && n){
		printf("%d\n", a[n - 1]);
	}

	return 0;
}
