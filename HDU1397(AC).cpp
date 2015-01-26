#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int isprime(int n)
{
	int i;

	if(n < 2)
	{
		return 0;
	}
	else if(n == 2)
	{
		return 1;
	}

	for(i = 2; i <= sqrt(n * 1.0); i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int *isprimes;
	int i;
	int n;
	int count;

	isprimes = (int *)malloc(32769 * sizeof(int));
	for(i = 0; i < 32769; i++)
	{
		isprimes[i] = isprime(i);
	}

	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		else if(n == 4)
		{
			printf("1\n");
		}
		else if(n % 2 == 0)
		{
			count = 0;
			for(i = 3; i <= n / 2; i++)
			{
				if(isprimes[i] == 1 && isprimes[n - i] == 1)
				{
					count++;
				}
			}

			printf("%d\n", count);
		}
	}

	free(isprimes);
	return 0;
}
