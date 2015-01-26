#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 n;
__int64 i;

int main()
{
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%I64d", &n);
			i = (int)sqrt(2.0 * n);
			while(i * (i + 1) / 2 < n){
				++i;
			}
			printf("%I64d\n", (n - i * (i - 1) / 2 - 1) % 9 + 1);
		}
	}

	return 0;
}
