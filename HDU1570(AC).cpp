#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	char s[10];
	int t, ti;
	int i;
	__int64 res, sum;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s%d%d", s, &n, &m);
			if(s[0] == 'A'){
				res = 1;
				for(i = n; i > n - m; --i){
					res *= i;
				}
				printf("%I64d\n", res);
			}else if(s[0] == 'C'){
				res = sum = 1;
				for(i = 1; i <= m; ++i){
					res *= (n + 1 - i);
					sum *= i;
					if(res % sum == 0){
						res /= sum;
						sum = 1;
					}
				}
				if(res % sum == 0){
					res /= sum;
					sum = 1;
				}
				printf("%I64d\n", res);
			}
		}
	}

	return 0;
}
