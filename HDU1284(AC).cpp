#include <cstdio>
using namespace std;

int main()
{
	int n, i;
	int res;

	while (scanf("%d", &n) == 1) {
		res = 0;
		for (i = 0; i * 3 <= n; ++i) {
			res += (n - i * 3) / 2 + 1;
		}
		printf("%d\n", res);
	}

	return 0;
}