#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double res;
	int e;
	int n;

	while(scanf("%d", &n) == 1 && n){
		e = 0;
		res = ((1.0 * n) * (1.0 * n + 1) * (2.0 * n + 1) / 6.0 + (1.0 * n) * (1.0 * n + 1) / 2.0) / 2.0;
		while(res >= 10.0){
			++e;
			res /= 10.0;
		}
		printf("%.2fE%d\n", res, e);
	}

	return 0;
}
