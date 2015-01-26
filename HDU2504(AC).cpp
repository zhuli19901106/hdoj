#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1000001;
int b[MAXN];
int prime[100000];
int pc;

int main()
{
	int i, j;
	int aa, bb, cc;
	int t, ti;

	memset(b, 0, MAXN * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i <= (MAXN - 1) / i; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j <= (MAXN - 1) / i; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i < MAXN; ++i){
		b[i] = !b[i];
		if(b[i]){
			prime[pc++] = i;
		}
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d", &aa, &bb);
			aa /= bb;
			for(i = 0; i < pc; ++i){
				if(aa % prime[i]){
					cc = prime[i] * bb;
					break;
				}
			}
			printf("%d\n", cc);
		}
	}

	return 0;
}
