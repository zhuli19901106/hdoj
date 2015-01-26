#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 700;
int f[1001][2][MAXN];
int res[1001][MAXN];

void add(int a[], int b[], int c[])
{
	int i;

	for(i = 0; i < MAXN; ++i){
		a[i] = b[i] + c[i];
	}

	for(i = 0; i < MAXN - 1; ++i){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}

void print(const int a[])
{
	int i;

	i = MAXN - 1;
	while(i >= 0 && a[i] == 0){
		--i;
	}
	if(i < 0){
		printf("0");
	}else{
		while(i >= 0){
			putchar(a[i] + '0');
			--i;
		}
	}
}

int main()
{
	int i;

	memset(f, 0, 1001 * 2 * MAXN * sizeof(int));
	f[1][0][0] = 1;
	f[1][1][0] = 0;
	f[2][0][0] = 1;
	f[2][1][0] = 1;
	for(i = 3; i <= 1000; ++i){
		add(f[i][0], f[i - 1][0], f[i - 1][1]);
		add(f[i][1], f[i - 2][0], f[i - 1][1]);
	}

	for(i = 1; i <= 1000; ++i){
		add(res[i], f[i][0], f[i][1]);
	}

	while(scanf("%d", &i) == 1){
		print(res[i]);
		printf("\n");
	}

	return 0;
}
