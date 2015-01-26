#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 3000005;
const int MAXP = 220000;
__int64 a[MAXN];
int p[MAXP];
int pc;

int main()
{
	int i, j;

	memset(a, 0, MAXN * sizeof(__int64));
	a[0] = a[1] = 1;
	for(i = 2; i <= 3000000 / i; ++i){
		if(a[i]){
			continue;
		}
		for(j = i; j <= 3000000 / i; ++j){
			a[i * j] = 1;
		}
	}
	pc = 0;
	for(i = 0; i <= 3000000; ++i){
		a[i] = !a[i];
		if(a[i]){
			p[pc++] = i;
		}
	}

	a[0] = a[1] = 0;
	for(i = 2; i <= 3000000; ++i){
		a[i] = i;
	}

	for(i = 0; i < pc; ++i){
		for(j = 1; p[i] * j <= 3000000; ++j){
			a[p[i] * j] = a[p[i] * j] / (p[i]) * (p[i] - 1);
		}
	}

	for(i = 1; i <= 3000000; ++i){
		a[i] = a[i - 1] + a[i];
	}

	while(scanf("%d%d", &i, &j) == 2){
		printf("%I64d\n", a[j] - a[i - 1]);
	}

	return 0;
}
