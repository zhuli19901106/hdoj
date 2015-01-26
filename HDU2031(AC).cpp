#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, r;
int a[1000], ac;

int main()
{
	int i;

	while(scanf("%d%d", &n, &r) == 2){
		if(n < 0){
			printf("-");
			n = -n;
		}
		if(n == 0){
			printf("0\n");
			continue;
		}
		ac = 0;
		while(n > 0){
			a[ac++] = n % r;
			n = n / r;
		}
		for(i = ac - 1; i >= 0; --i){
			if(a[i] >= 0 && a[i] <= 9){
				printf("%d", a[i]);
			}else{
				printf("%c", a[i] - 10 + 'A');
			}
		}
		printf("\n");
	}

	return 0;
}
