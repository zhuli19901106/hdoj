#include <cstdio>
using namespace std;

int main()
{
	int i;
	int m, n;

	while (scanf("%d", &n) == 1) {
		i = 1;
		m = 0;
		while (true) {
			if (i <= n) {
				i = 2 * i;
			} else {
				i = 2 * (i - n) - 1;
			}
			++m;
			if (i == 1) {
				break;
			}
		}
		printf("%d\n", m);
	}

	return 0;
}