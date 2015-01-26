#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct st{
	double x, y;
}st;

void myswap(double &x, double &y)
{
	double t;

	t = x;
	x = y;
	y = x;
}

int main()
{
	st p1, p2, p3, p4;
	st pp1, pp2;
	double t;

	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) == 8){
		if(p1.x > p2.x){
			t = p1.x;
			p1.x = p2.x;
			p2.x = t;
		}
		if(p1.y > p2.y){
			t = p1.y;
			p1.y = p2.y;
			p2.y = t;
		}
		if(p3.x > p4.x){
			t = p3.x;
			p3.x = p4.x;
			p4.x = t;
		}
		if(p3.y > p4.y){
			t = p3.y;
			p3.y = p4.y;
			p4.y = t;
		}

		if(p1.x >= p4.x || p2.x <= p3.x || p1.y >= p4.y || p2.y <= p3.y){
			printf("0.00\n");
		}else{
			if(p1.x > p3.x){
				pp1.x = p1.x;
			}else{
				pp1.x = p3.x;
			}
			if(p1.y > p3.y){
				pp1.y = p1.y;
			}else{
				pp1.y = p3.y;
			}
			if(p2.x < p4.x){
				pp2.x = p2.x;
			}else{
				pp2.x = p4.x;
			}
			if(p2.y < p4.y){
				pp2.y = p2.y;
			}else{
				pp2.y = p4.y;
			}
			printf("%.2lf\n", (pp2.x - pp1.x) * (pp2.y - pp1.y));
		}
	}

	return 0;
}
