#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

__int64 mypow(__int64 a, __int64 b, __int64 c)
{
	if(b < 0){
		return 0;
	}else if(b == 0){
		return 1 % c;
	}else if(b == 1){
		return a % c;
	}else if(b % 2){
		__int64 tmp;

		tmp = mypow(a, b / 2, c);
		return (a % c) * (tmp * tmp % c) % c;
	}else{
		__int64 tmp;

		tmp = mypow(a, b / 2, c);
		return (tmp * tmp) % c;
	}
}

int main()
{
	__int64 a, b, c;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%I64d%I64d%I64d", &a, &b, &c);
			printf("%I64d\n", mypow(a, b, c));
		}
	}

	return 0;
}
