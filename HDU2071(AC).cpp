#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double tmp, res;
	int t, n;
	int ti, i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			scanf("%lf", &res);
			for(i = 1; i < n; ++i){
				scanf("%lf", &tmp);
				if(tmp > res){
					res = tmp;
				}
			}
			printf("%.2f\n", res);
		}
	}

	return 0;
}
