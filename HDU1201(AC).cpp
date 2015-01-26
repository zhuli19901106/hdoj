#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
double sum_c, c;
double sum_p, p;
double sc;

inline bool isleap(int n)
{
	return (n % 100 == 0) ? (n % 400 == 0) : (n % 4 == 0);
}

int main()
{
	int y, m, d;
	int n, ni;
	int i;
	int res;

	while(scanf("%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			res = 18 * 365;
			scanf("%04d%*1s%02d%*1s%02d", &y, &m, &d);
			if(m == 2 && d == 29){
				printf("-1\n");
			}else if(m > 2){
				for(i = y + 1; i <= y + 18; ++i){
					if(isleap(i)){
						++res;
					}
				}
				printf("%d\n", res);
			}else{
				for(i = y; i <= y + 17; ++i){
					if(isleap(i)){
						++res;
					}
				}
				printf("%d\n", res);
			}
		}
	}

	return 0;
}
