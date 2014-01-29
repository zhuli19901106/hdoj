#include <cstdio>
#include <cstdlib>
using namespace std;

// 2004^x = 2^(2*x) * 3^(x) * 167^(x);

int mypow(int p, int n)
{
	if (n == 0) {
		return 1;
	}
	int tmp = mypow(p, n / 2);
	if (n % 2) {
		return p * tmp * tmp % 29;
	} else {
		return tmp * tmp % 29;
	}
}

int calc_poly(int p, int n)
{
	if (n == 0) {
		return 1;
	}
	if (n % 2) {
		int tmp = calc_poly(p, n / 2);
		return (tmp + mypow(p, (n + 1) / 2) * tmp) % 29;
	} else {
		return (1 + p * calc_poly(p, n - 1)) % 29;
	}
}

int main()
{
	int res;
	int x;

	while (scanf("%d", &x) == 1 && x) {
		res = 1;
		res = res * calc_poly(2, 2 * x) % 29;
		res = res * calc_poly(3, x) % 29;
		res = res * calc_poly(167, x) % 29;
		printf("%d\n", res);
	}

	return 0;
}