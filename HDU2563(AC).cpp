#include <cstdio>
using namespace std;

int main()
{
	int i;
	int a[21];
	int c, ci;

	a[1] = 3;
	a[2] = 7;
	for (i = 3; i <= 20; ++i) {
		a[i] = 2 * a[i - 1] + a[i - 2];
	}

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d", &i);
			printf("%d\n", a[i]);
		}
	}

	return 0;
}