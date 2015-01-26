#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double sum;
	int n;
	int i;
	int j;
	int num;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num == 1)
		{
			printf("1\n");
		}
		else
		{
			sum = 0;
			for(j = 2; j <= num; j++)
			{
				sum = sum + log(j * 1.0) / log(10.0);
			}
			printf("%d\n", (int)(sum + 1));
		}
	}

	return 0;
}
