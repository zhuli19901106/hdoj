#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int m;
	int n;

	int i;
	int t;

	while(true)
	{
		if(scanf("%d", &t) != 1)
		{
			break;
		}

		for(i = 0; i < t; i++)
		{
			scanf("%d%d", &m, &n);
			if(m % 2 == 0 || n % 2 == 0)
			{
				printf("Scenario #%d:\n", i + 1);
				printf("%0.2f\n\n", 1.0 * m * n);
			}
			else
			{
				printf("Scenario #%d:\n", i + 1);
				printf("%0.2f\n\n", 1.0 * m * n - 1 + sqrt(2.0));
			}
		}
	}

	return 0;
}
