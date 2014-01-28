#include <cstdio>
using namespace std;

int main()
{
	int n;
	int res;
	int c, ci;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d", &n);
			res = 0;
			while (n > 0) {
				n = n & (n - 1);
				++res;
			}
			printf("%d\n", res);
		}
	}

	return 0;
}