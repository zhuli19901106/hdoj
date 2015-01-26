#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int i;
	int t;
	long n;
	long p;

	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%ld", &n);
		p = 0;
		while(n % 2 == 0)
		{
			p++;
			n = n / 2;
		}

		printf("%ld %d\n", n, p);
	}

	return 0;
}
