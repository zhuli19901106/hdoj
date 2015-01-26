#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

int main()
{
	double p, q;
	int n, ni;
	int i;

	while(scanf("%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			scanf("%lf%lf", &p, &q);
			i = 2;
			while(i > 1)
			{
				if((int)(q * i * 0.01) - (int)(p * i * 0.01) == 1){
					break;
				}
				++i;
			}
			printf("%d\n", i);
		}
	}

	return 0;
}
