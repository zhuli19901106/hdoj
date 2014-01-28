#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 101;
const int MAXLEN = 58;
int res[MAXN][MAXLEN];
int tmp[MAXLEN];
int i;

void print_digit(const int a[])
{
	int i;

	i = MAXLEN - 1;
	while (i > 0 && a[i] == 0) {
		--i;
	}
	while (i >= 0) {
		putchar(a[i] + '0');
		--i;
	}
}

void multiply_digit(int a[], int b[], int c[])
{
	int i, j;

	for (i = 0; i < MAXLEN; ++i) {
		for (j = 0; i + j < MAXLEN; ++j) {
			c[i + j] += a[i] * b[j];
		}
	}

	for (i = 0; i < MAXLEN - 1; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c[MAXLEN - 1] %= 10;
}

void addto_digit(int a[], int b[])
{
	int i;

	for (i = 0; i < MAXLEN; ++i) {
		a[i] = a[i] + b[i];
	}

	for (i = 0; i < MAXLEN - 1; ++i) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	a[MAXLEN - 1] %= 10;
}

int main()
{
	int i, j;

	memset(res, 0, MAXN * MAXLEN * sizeof(int));
	res[0][0] = 1;
	res[1][0] = 1;
	for (i = 2; i <= 100; ++i) {
		for (j = 0; j < i; ++j) {
			memset(tmp, 0, MAXLEN * sizeof(int));
			multiply_digit(res[j], res[i - 1 - j], tmp);
			addto_digit(res[i], tmp);
		}
		
		if (res[i][MAXLEN - 1] > 0) {
			printf("overflow at res[%d]\n", i);
			exit(0);
		}
	}

	while (scanf("%d", &i) == 1) {
		if (i < 0 || i >= MAXN) {
			continue;
		}
		print_digit(res[i]);
		putchar('\n');
	}

	return 0;
}