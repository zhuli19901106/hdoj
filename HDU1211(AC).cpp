#include <cstdio>
#include <cstdlib>
using namespace std;

typedef __int64 LL;

void ext_gcd(LL e, LL f, LL &x, LL &y)
{
	if (e == 0) {
		x = 0;
		y = 1;
	} else {
		ext_gcd(f % e, e, x, y);
		int tmp = x;
		x = y - f / e * x;
		y = tmp;
	}
}

int main()
{
	LL p, q, e, n, f;
	int cc, i, j;
	LL x, y;

	while (scanf("%I64d%I64d%I64d%d", &p, &q, &e, &cc) == 4) {
		n = p * q;
		f = (p - 1) * (q - 1);
		ext_gcd(e, f, x, y);
		if (x < 0) {
			x = (f - (f - x) % f) % f;
		}
		for (i = 0; i < cc; ++i) {
			scanf("%I64d", &y);
			f = 1;
			for (j = 0; j < x; ++j) {
				f = (f * y) % n;
			}
			putchar((int)f);
		}
		putchar('\n');
	}

	return 0;
}