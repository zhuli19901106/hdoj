#define _CRT_SECURE_NO_WARNININGS
#include <cstdio>
using namespace std;

int main()
{
	long n;
	long m;
	long c;
	long result;

	while(1)
	{
		scanf("%ld%ld%ld", &n, &m, &c);
		if(n == 0 && m == 0 && c == 0)
		{
			break;
		}

		if(m < 8 || n < 8)
		{
			printf("0\n");
		}
		else
		{
			if((m - 7) % 2 == 0 || (n - 7) % 2 == 0)
			{
				result = (n - 7) * (m - 7) / 2;
			}
			else
			{
				if(c == 1)
				{
					result = ((n - 7) * (m - 7) + 1) / 2;
				}
				else
				{
					result = ((n - 7) * (m - 7) - 1) / 2;
				}
			}

			printf("%ld\n", result);
		}
	}

	return 0;
}
