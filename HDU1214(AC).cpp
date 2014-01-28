#include <cstdio>
using namespace std;

int main()
{
	int n;

	while (scanf("%d", &n) == 1) {
		if (n % 2) {
			printf("%d\n", n / 2 + (n / 2 - 1) * (n / 2));
		} else {
			printf("%d\n", (n / 2 - 1) * (n / 2));
		}
	}

	return 0;
}