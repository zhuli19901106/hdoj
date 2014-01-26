#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int a[105];
	int n, i, n2;
	int sum;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		sum = 0;
		n2 = n / 2 + 1;
		for (i = 0; i < n2; ++i) {
			sum += a[i] / 2 + 1;
		}
		printf("%d\n", sum);
	}

	return 0;
}