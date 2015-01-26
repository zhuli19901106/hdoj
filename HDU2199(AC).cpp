#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

inline double f(const double &x, const double &y)
{
	return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6 - y;
}

inline double myabs(const double &d)
{
	return (d >= 0 ? d : -d);
}

int main()
{
	double y;
	double left, right, mid;
	double val;
	const double err = 1e-10;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lf", &y);

			if(f(0.0, y) > 0 || f(100.0, y) < 0){
				printf("No solution!\n");
			}else{
				left = 0.0;
				right = 100.0;
				while(myabs(left - right) >= err){
					mid = left + (right - left) / 2.0;
					val = f(mid, y);
					if(val > 0){
						right = mid;
					}else{
						left = mid;
					}
				}

				printf("%.4f\n", mid);
			}
		}
	}

	return 0;
}
