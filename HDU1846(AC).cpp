#include <cstdio>
using namespace std;

int main()
{
	int c, ci;
	int n, m;

	if (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d%d", &n, &m);
			if (n % (1 + m)) {
				printf("first\n");
			} else {
				printf("second\n");
			}
		}
	}

	return 0;
}