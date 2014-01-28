#include <cstdio>
using namespace std;

int n;
const int MAXN = 10000;
int a[MAXN];
int b[MAXN];

int main()
{
	int i;
	int j;

	while (scanf("%d",&n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 1; i <= 26; ++i) {
			for (j = 0; j < n; ++j) {
				b[j] = a[j] ^ i;
				if (b[j] < 1 || b[j] > 26) {
					break;
				}
			}
			if (j == n) {
				break;
			}
		}
		for (i = 0; i < n; ++i) {
			putchar('A' - 1 + b[i]);
		}
		putchar('\n');
	}

	return 0;
}