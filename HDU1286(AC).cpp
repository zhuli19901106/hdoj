#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 32768;
int n;
int b[MAXN];
int p[5000];
int pc;

int main()
{
	int i, j;
	int t, ti;

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

	b[0] = 0;
	b[1] = 0;
	for(i = 2; i < MAXN; ++i){
		b[i] = i;
	}
	for(i = 0; i < pc; ++i){
		for(j = 1; j * p[i] < MAXN; ++j){
			b[j * p[i]] = b[j * p[i]] / p[i] * (p[i] - 1);
		}
	}

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			printf("%d\n", b[n]);
		}
	}

	return 0;
}
