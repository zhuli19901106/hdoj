#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double r;

	while(scanf("%lf", &r) == 1 && r != 0.0){
		printf("%.3f %.3f\n", r * sqrt(1.0 / 3.0), r * sqrt(2.0 / 3.0));
	}

	return 0;
}
