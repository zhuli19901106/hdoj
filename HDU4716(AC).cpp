#include <cstdio>
using namespace std;

int main()
{
	int c, ci;
	int n, i;

	while (scanf("%d", &c) == 1) {
		for (ci = 1; ci <= c; ++ci) {
			scanf("%d", &n);
			printf("Case #%d:\n", ci);
			printf("*------------*\n");
			for (i = 0; i < (100 - n) / 10; ++i) {
				printf("|............|\n");
			}
			for (i = 0; i < n / 10; ++i) {
				printf("|------------|\n");
			}
			printf("*------------*\n");
		}
	}

	return 0;
}