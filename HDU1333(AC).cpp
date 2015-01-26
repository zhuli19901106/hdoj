#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

long getdigitsum(long n)
{
	long dsum;
	long digit;

	dsum = 0;
	while(n > 0)
	{
		digit = n % 10;
		dsum = dsum + digit;
		n = (n - digit) / 10;
	}

	return dsum;
}

long getsum(long n)
{
	long n0;
	long sum;
	long total;
	long i;

	n0 = n;
	total = 0;
	for(i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			sum = getdigitsum(i);
		}
		while(n % i == 0)
		{
			total = total + sum;
			n = n / i;
		}
	}

	if(n == n0)
	{
		return -1;
	}

	if(n > 1)
	{
		total = total + getdigitsum(n);
	}

	return total;
}

int main()
{
	long n;
	long i;

	while(1)
	{
		if(scanf("%ld", &n) != 1)
		{
			break;
		}

		if(n == 0)
		{
			break;
		}

		i = n + 1;
		while(getsum(i) != getdigitsum(i))
		{
			i++;
		}

		printf("%ld\n", i);
	}

	return 0;
}
