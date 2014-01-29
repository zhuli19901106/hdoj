#include <cstdio>
using namespace std;

const int MAXN = 200005;
int a[MAXN];
int n;

int main()
{
	int x, y;
	int i;
	int sum;
	int cc, mcc;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			a[i] = a[i + n] = x - y;
		}
		sum = 0;
		cc = 0;
		mcc = 0;
		for (i = 0; i < 2 * n; ++i) {
			sum += a[i];
			if (sum < 0) {
				sum = 0;
				cc = 0;
			} else {
				++cc;
			}
			if (cc > mcc) {
				mcc = cc;
			}
			if (cc >= n) {
				break;
			}
		}
		printf("%d\n", mcc);
	}

	return 0;
}