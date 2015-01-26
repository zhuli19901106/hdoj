#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double x1, y1, x2, y2;
	double res;
	const double pi = 3.1415926;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			res = acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 *y1) * sqrt(x2 * x2 + y2 * y2))) * 180 / pi;
			printf("%.2f\n", res);
		}
	}

	return 0;
}
