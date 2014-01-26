#include <cstdio>
using namespace std;

int main()
{
	int x;
	int i, j;
	int c, ci;

	while (scanf("%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			scanf("%d", &x);
			for (i = 0; i < x / 2; ++i) {
				for (j = 0; j < i; ++j) {
					putchar(' ');
				}
				putchar('X');
				for (j = 0; j < x - 2 - 2 * i; ++j) {
					putchar(' ');
				}
				putchar('X');
				putchar('\n');
			}
			for (j = 0; j < x / 2; ++j) {
				putchar(' ');
			}
			putchar('X');
			putchar('\n');
			for (i = 0; i < x / 2; ++i) {
				for (j = 0; j < (x - 3) / 2 - i; ++j) {
					putchar(' ');
				}
				putchar('X');
				for (j = 0; j < 1 + 2 * i; ++j) {
					putchar(' ');
				}
				putchar('X');
				putchar('\n');
			}
			putchar('\n');
		}
	}

	return 0;
}