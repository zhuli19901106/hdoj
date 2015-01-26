#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	__int64 n;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%I64d", &n);
			printf("%I64d %I64d\n", n * n * n, (n + 1) * (n + 1) * (n + 1));
		}
	}

	return 0;
}
