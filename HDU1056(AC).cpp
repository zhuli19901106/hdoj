#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	double len;
	double sum;

	while(true)
	{
		scanf("%lf", &len);
		if(len <= 0)
		{
			break;
		}

		i = 2;
		sum = 0;
		while(1)
		{
			sum = sum + 1.0 / i;
			if(sum >= len)
			{
				break;
			}
			else
			{
				i++;
			}
		}

		printf("%d card(s)\n", i - 1);
	}

	return 0;
}
