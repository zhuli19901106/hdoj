#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100;
int a[MAXN];
int b[MAXN];
int cc;
int n;

int main()
{
	int ti;
	int i;

	ti = 0;
	while(scanf("%d", &n) == 1 && n >= 0){
		++ti;
		if(ti > 1){
			printf("\n");
		}
		cc = 0;
		printf("Case %d.\n", ti);

		i = 2;
		while(i <= n / i){
			if(n % i == 0){
				a[cc++] = i;
				b[cc - 1] = 0;
				while(n % i == 0){
					++b[cc - 1];
					n /= i;
				}
			}
			++i;
		}
		if(n > 1){
			a[cc++] = n;
			b[cc - 1] = 1;
			n = 1;
		}

		for(i = 0; i < cc; ++i){
			printf("%d %d ", a[i], b[i]);
		}
		printf("\n");
	}

	return 0;
}
