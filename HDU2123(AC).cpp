#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i, j;
	int t, ti;
	int n;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			for(i = 1; i <= n; ++i){
				for(j = 1; j <= n; ++j){
					printf((j == 1 ? "%d" : " %d"), i * j);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
