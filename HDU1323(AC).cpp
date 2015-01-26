#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
using namespace std;

int GetSum(int n)
{
	int i;
	int sum;
	double rt;

	if(n == 1)
	{
		return 0;
	}

	rt = sqrt(1.0 * n);
	sum = 1;
	for(i = 2; i <= rt; i++)
	{
		if(n % i == 0)
		{
			sum = sum + i;
			if(i < n / i)
			{
				sum = sum + n / i;
			}
		}
	}

	return sum;
}

int main()
{
	int n;
	int sum;

	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			break;
		}

		sum = GetSum(n);
		printf("%5d  ", n);
		if(sum > n)
		{
			printf("ABUNDANT\n");
		}
		else if(sum == n)
		{
			printf("PERFECT\n");
		}
		else
		{
			printf("DEFICIENT\n");
		}
	}
	printf("END OF OUTPUT\n");

	return 0;
}
