#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
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
	int i, j, k;
	bool suc;

	while(scanf("%d", &n) == 1){
		suc = false;
		for(i = 1; 3 * i * i <= n; ++i){
			for(j = i; i * i + 2 * j * j <= n; ++j){
				k = (int)sqrt(1.0 * n  - i * i - j * j);
				if(k * k == (n - i * i - j * j) && k >= j){
					suc = true;
				}
				if(suc){
					break;
				}
			}
			if(suc){
				break;
			}
		}

		if(suc){
			printf("%d %d %d\n", i, j, k);
		}
	}

	return 0;
}
