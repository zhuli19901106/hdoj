#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int t, ti;
	int a, b;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &a, &b);
			printf("%d\n", (a % 100 + b % 100) % 100);
		}
	}

	return 0;
}
