#include <cstdio>
using namespace std;

int main()
{
	int n;

	while (scanf("%d", &n) == 1) {
		printf("%d\n", 1 + n + n * (n - 1) / 2 + n * (n - 1) * (n - 2) / 6);
	}

	return 0;
}