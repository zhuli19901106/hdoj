#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	int i;

	while(scanf("%d%d", &m, &n) == 2){
		if(m < n + 1){
			i = (m > 1 ? m : 1);
			printf("%d", i);
			for(++i; i <= n; ++i){
				printf(" %d", i);
			}
			printf("\n");
		}else if(m % (n + 1) == 0){
			printf("none\n");
		}else{
			printf("%d\n", m % (n + 1));
		}
	}

	return 0;
}
