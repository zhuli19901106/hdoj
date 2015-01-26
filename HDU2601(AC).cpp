#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 n;
int res, rt;

int main()
{
	int i;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%I64d", &n);
			++n;
			res = 0;
			rt = (int)sqrt(1.0 * n);
			for(i = 2; i <= rt; ++i){
				if(n % i == 0){
					++res;
				}
			}
			printf("%d\n", res);
		}
	}

	return 0;
}
