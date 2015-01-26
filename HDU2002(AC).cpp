#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const double pi = 3.1415927;
double rad;

int main()
{
	while(scanf("%lf", &rad) == 1){
		printf("%.3f\n", 4 * pi / 3 * rad * rad * rad);
	}

	return 0;
}
