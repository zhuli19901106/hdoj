#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int min(int a, int b)
{
	return (a > b ? b : a);
}

int main()
{
	int twos;
	int fives;
	int base;
	int n;
	int t;
	int ti;

	scanf("%d", &t);
	for(ti = 0; ti < t; ti++)
	{
		scanf("%d", &n);

		twos = 0;
		base = 2;
		while(base <= n)
		{
			twos += n / base;
			base = base * 2;
		}

		fives = 0;
		base = 5;
		while(base <= n)
		{
			fives += n / base;
			base = base * 5;
		}

		printf("%d\n", min(twos, fives));
	}

	return 0;
}
