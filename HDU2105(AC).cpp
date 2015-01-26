#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double a, b, c, d, e, f;
	int n;
	
	while(scanf("%d", &n) == 1 && n){
		while(n--){
			scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
			printf("%.1f %.1f\n", (a + c + e) / 3.0, (b + d + f) / 3.0);
		}
	}

	return 0;
}
