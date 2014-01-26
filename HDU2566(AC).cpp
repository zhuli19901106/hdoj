#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double ll, rr;
	int l, r;
	int m, n;
	int c, ci;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d%d", &n, &m);
			ll = (1.0 * m - 2 * n) / 3;
			if (ll < 0) {
				ll = 0;
			}
			l = (int)ceil(ll);
			rr = (1.0 * m - n) / 4;
			r = rr;
			if (l <= r) {
				printf("%d\n", r - l + 1);
			} else {
				printf("0\n");
			}
		}
	}

	return 0;
}