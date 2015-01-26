#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int a[1000];
	int n;
	int i;
	int ave;
	int sum;
	int counter;

	counter = 0;
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		else
		{
			counter++;
		}

		ave = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			ave = ave + a[i];
		}
		ave = ave / n;

		sum = 0;
		for(i = 0; i < n; i++)
		{
			if(a[i] > ave)
			{
				sum = sum + a[i] - ave;
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", counter, sum);
	}

	return 0;
}
