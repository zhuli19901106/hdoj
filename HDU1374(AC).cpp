#define _CRTT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
using namespace std;

void getabc(double x1, double y1, double x2, double y2, double *a, double *b, double *c)
{
	if(x1 == x2 && y1 != y2)
	{
		*a = 1;
		*b = 0;
		*c = -x1;
		return;
	}

	*a = -(y2 - y1) / (x2 - x1);
	*b = 1;
	*c = (((-*a) * x1 - y1) + ((-*a) * x2 - y2)) / 2;
}

void getintersect(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	if(a1 * b2 - a2 * b1 == 0)
	{
		return;
	}

	*x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
	*y = (c2 * a1 - c1 * a2) / (a2 * b1 - a1 * b2);
}


int main()
{
	double x[3];
	double y[3];
	double ta;
	double tb;
	double tc;
	double a1;
	double b1;
	double c1;
	double a2;
	double b2;
	double c2;
	double cx;
	double cy;
	double mid01x;
	double mid01y;
	double mid12x;
	double mid12y;
	double radius;
	const double pi = 3.1415926535897932384626433832795;

	while(1)
	{
		if(scanf("%lf%lf%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]) != 6)
		{
			break;
		}

		mid01x = (x[0] + x[1]) / 2;
		mid01y = (y[0] + y[1]) / 2;
		getabc(x[0], y[0], x[1], y[1], &ta, &tb, &tc);
		a1 = -tb;
		b1 = ta;
		c1 = -(a1 * mid01x + b1 * mid01y);

		mid12x = (x[1] + x[2]) / 2;
		mid12y = (y[1] + y[2]) / 2;
		getabc(x[1], y[1], x[2], y[2], &ta, &tb, &tc);
		a2 = -tb;
		b2 = ta;
		c2 = -(a2 * mid12x + b2 * mid12y);

		getintersect(a1, b1, c1, a2, b2, c2, &cx, &cy);

		radius = sqrt((cx - x[0]) * (cx - x[0]) + (cy - y[0]) * (cy - y[0]));

		printf("%.2lf\n", 2 * pi * radius);
	}

	return 0;
}
