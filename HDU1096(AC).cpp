#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int t;
	int n, i, sum, tmp;

	while(scanf("%d", &t) == 1){
		while(t--){
			scanf("%d", &n);
			sum = 0;
			for(i = 0; i < n; ++i){
				scanf("%d", &tmp);
				sum += tmp;
			}
			printf("%d\n", sum);
			if(t > 0){
				printf("\n");
			}
		}
	}

	return 0;
}
