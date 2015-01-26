#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int i;
	int j;
	int k;
	int n;
	int a[20];
	int sum;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &k);
		sum = 0;
		for(j = 0; j < k; j++)
		{
			scanf("%d", &a[j]);
			sum = sum + a[j];
		}

		sum = sum - k + 1;
		printf("%d\n", sum);
	}

	return 0;
}
