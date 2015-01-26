#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;

int main()
{
	int p, q;
	int i;
	int x, y;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		m *= 2;
		for(i = (int)sqrt(1.0 * m); i >= 1; --i){
			if(m % i == 0){
				x = i;
				y = m / x;
				if((y - x) % 2){
					p = (y - x + 1) / 2;
					q = (y + x - 1) / 2;
					if(p >= 1 && p <= n && q >= 1 && q <= n && p <= q){
						printf("[%d,%d]\n", p, q);
					}
				}
			}
		}
		printf("\n");
	}

	return 0;
}
