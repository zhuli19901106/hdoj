#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double a[100], sum;
int n;

int main()
{
	int i;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%lf", &a[i]);
		}
		sort(a, a + n);
		sum = 0;
		for(i = 1; i < n - 1; ++i){
			sum += a[i];
		}
		sum = sum / (n - 2);
		printf("%.2f\n", sum);
	}

	return 0;
}
