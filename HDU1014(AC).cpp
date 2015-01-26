#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	if(a == b)
	{
		return a;
	}
	else
	{
		while(1)
		{
			if(a > b)
			{
				if(a % b == 0)
				{
					return b;
				}
				else
				{
					a = a % b;
				}
			}
			else
			{
				if(b % a == 0)
				{
					return a;
				}
				else
				{
					b = b % a;
				}
			}
		}
	}
}

int main()
{
	int step;
	int mod;

	while(1)
	{
		if(scanf("%d%d", &step, &mod) != 2)
		{
			break;
		}


		if(gcd(step, mod) == 1)
		{
			printf("%10d%10d    Good Choice\n", step, mod);
		}
		else
		{
			printf("%10d%10d    Bad Choice\n", step, mod);
		}
		printf("\n");
	}

	return 0;
}
