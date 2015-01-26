#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int rem;
	int expo;

	while(1)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}
		else if(n % 2 == 0 || n == 1)
		{
			printf("2^? mod %d = 1\n", n);
		}
		else
		{
			expo = 2;
			rem = 4 % n;
			while(rem != 1)
			{
				rem = rem * 2 % n;
				expo++;
			}

			printf("2^%d mod %d = 1\n", expo, n);
		}
	}

	return 0;
}
