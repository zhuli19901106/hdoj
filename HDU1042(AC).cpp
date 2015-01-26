#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 10000;
int a[MAXN];
//high precision based on radix 10000

int main()
{
	int n;
	int i, j;

	while(scanf("%d", &n) == 1){
		memset(a, 0, MAXN * sizeof(int));
		a[0] = 1;
		for(i = 1; i <= n; ++i){
			j = MAXN - 1;
			while(j >= 0 && a[j] == 0){
				--j;
			}
			while(j >= 0){
				a[j] *= i;
				--j;
			}
			for(j = 0; j < MAXN - 1; ++j){
				if(a[j] > 0){
					a[j + 1] += a[j] / 10000;
					a[j] %= 10000;
				}
			}
			a[MAXN - 1] %= 10000;
		}

		i = MAXN - 1;
		while(i >= 0 && a[i] == 0){
			--i;
		}
		printf("%d", a[i]);
		--i;
		while(i >= 0){
			printf("%04d", a[i]);
			--i;
		}
		printf("\n");
	}
	
	return 0;
}
