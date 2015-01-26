#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

double myabs(const double &d)
{
	return (d >= 0 ? d : -d);
}

int main()
{
	double h, m, s;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lf%lf%lf", &h, &m, &s);
			if(h >= 12){
				h -= 12;
			}
			s = myabs((h + m / 60 + s / 3600) * 30 - (m + s / 60) * 6);
			if(s >= 180){
				s = 360 - s;
			}
			printf("%d\n", (int)s);
		}
	}

	return 0;
}
