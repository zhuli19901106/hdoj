#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 5001;
int b[MAXN];
int p[MAXN];
int pc;
int c[MAXN];
int res[MAXN];

int main()
{
	int i, j;
	int x, y;
	int pro;
	int n, ni;

	memset(b, 0, MAXN * sizeof(int));
	b[0] = 1;
	b[1] = 1;
	for(i = 2; i * i < MAXN; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j * i < MAXN; ++j){
			b[j * i] = 1;
		}
	}

	pc = 0;
	for(i = 0; i < MAXN; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	memset(res, 0, MAXN * sizeof(int));
	for(i = 1; i < MAXN; ++i){
		res[i] = 1;
	}

	for(i = 0; i < pc; ++i){
		pro = 1;
		memset(c, 0, MAXN * sizeof(int));
		while(pro < MAXN){
			pro *= p[i];
			j = 1;
			while(j * pro < MAXN){
				++c[j * pro];
				++j;
			}
		}
		for(j = p[i]; j <= MAXN; j += p[i]){
			res[j] *= (c[j] + 1);
		}
	}

	/*
	for(i = 0; i < MAXN; ++i){
		printf("g(%d) = %d\n", i, res[i]);
	}
	*/

	while(scanf("%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			scanf("%d%d", &x, &y);
			j = x;
			for(i = x + 1; i <= y; ++i){
				if(res[i] > res[j]){
					j = i;
				}
			}
			printf("%d\n", j);
		}
	}

	return 0;
}
