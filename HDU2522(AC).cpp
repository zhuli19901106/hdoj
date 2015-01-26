#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[100005];
int n;

int main()
{
	int rem;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			if(n < 0){
				printf("-");
				n = -n;
			}
			if(n == 1){
				printf("1.0\n");
				continue;
			}
			printf("0.");
			memset(a, 0, n * sizeof(int));
			rem = 1;
			while(rem && !a[rem]){
				a[rem] = 1;
				rem = rem * 10;
				printf("%d", rem / n);
				rem %= n;
			}
			printf("\n");
		}
	}

	return 0;
}
