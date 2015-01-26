#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, c;
	int d, e, f;
	int res;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
			res = (a + d) * 3600 + (b + e) * 60 + (c + f);
			printf("%d %d %d\n", res / 3600, res % 3600 / 60, res % 60);
		}
	}

	return 0;
}
