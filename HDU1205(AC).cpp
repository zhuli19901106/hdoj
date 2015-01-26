#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	__int64 sum;
	__int64 tmp;
	__int64 maxv;
	int n, i;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			scanf("%I64d", &maxv);
			sum = maxv;
			for(i = 1; i < n; ++i){
				scanf("%I64d", &tmp);
				if(tmp > maxv){
					maxv = tmp;
				}
				sum += tmp;
			}

			if(maxv > (sum + 1) / 2){
				printf("No\n");
			}else{
				printf("Yes\n");
			}
		}
	}

	return 0;
}
