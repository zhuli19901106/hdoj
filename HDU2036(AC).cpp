#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

double x[200];
double y[200];
int n;
double res;

int main()
{
	int i;

	while(scanf("%d", &n) == 1 && n){
		for(i = 0; i < n; ++i){
			scanf("%lf%lf", &x[i], &y[i]);
		}

		res = 0;
		for(i = 0; i < n - 1; ++i){
			res += x[i] * y[i + 1] - x[i + 1] * y[i];
		}
		res += x[n - 1] * y[0] - x[0] * y[n - 1];

		res = res / 2;
		if(res < 0){
			res = -res;
		}

		printf("%.1f\n", res);
	}

	return 0;
}
