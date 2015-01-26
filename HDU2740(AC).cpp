#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int b;
	int n;
	int dif1;
	int dif2;
	double dr;

	while(1)
	{
		scanf("%d%d", &b, &n);
		if(b == 0 && n == 0)
		{
			break;
		}

		dr = pow(1.0 * b, 1.0 / n);
		dif1 = b - (int)pow(((int)dr) * 1.0, n);
		dif2 = (int)pow(((int)dr + 1) * 1.0, n) - b;

		if(dif1 < dif2)
		{
			printf("%d\n", (int)dr);
		}
		else
		{
			printf("%d\n", (int)dr + 1);
		}
	}

	return 0;
}
