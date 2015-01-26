#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double h, u, d, f;
	double su;
	double p;
	int cd;
	
	while(true){
		if(scanf("%lf%lf%lf%lf", &h, &u, &d, &f) != 4){
			break;
		}else if(0.0 == h){
			break;
		}
		
		su = u * f / 100.0;
		p = 0;
		cd = 1;
		while(true){
			p = p + u;
			if(p > h){
				break;
			}else{
				p = p - d;
				if(p < 0){
					break;
				}
			}
			u = u - su;
			if(u <= 0){
				u = 0;
			}
			++cd;
		}
		if(p > h){
			printf("success on day %d\n", cd);
		}else if(p < 0.0){
			printf("failure on day %d\n", cd);
		}
	}
	
	return 0;
}
