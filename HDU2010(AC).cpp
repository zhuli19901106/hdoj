#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int b[1000];
int m, n, c;

int f(int n)
{
	int a, b, c;

	a = n / 100;
	b = n % 100 / 10;
	c = n % 10;

	if(a * a * a + b * b * b + c * c * c == n){
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int i;

	for(i = 100; i <= 999; ++i){
		if(f(i)){
			b[i] = 1;
		}
	}

	while(scanf("%d%d", &m, &n) == 2){
		c = 0;
		for(i = m; i <= n; ++i){
			if(b[i]){
				if(c == 0){
					printf("%d", i);
				}else{
					printf(" %d", i);
				}
				++c;
			}
		}
		if(c == 0){
			printf("no");
		}
		printf("\n");
	}

	return 0;
}
