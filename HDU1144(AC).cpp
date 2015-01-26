#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int k;
	int m;
	int cat[100][100];
	int c[100];
	int r[100];
	int studied[100];
	int count[100];
	int i;
	int j;
	int p;
	int q;
	int s;

	while(1)
	{
		scanf("%d", &k);
		if(k == 0)
		{
			break;
		}
		scanf("%d", &m);

		for(i = 0; i < k; i++)
		{
			scanf("%d", &studied[i]);
		}

		for(i = 0; i < m; i++)
		{
			scanf("%d%d", &c[i], &r[i]);
			for(j = 0; j < c[i]; j++)
			{
				scanf("%d", &cat[i][j]);
			}
		}

		for(i = 0; i < m; i++)
		{
			count[i] = 0;
		}

		for(p = 0; p < k; p++)
		{
			for(q = 0; q < m; q++)
			{
				for(s = 0; s < c[q]; s++)
				{
					if(studied[p] == cat[q][s])
					{
						count[q]++;
					}
				}
			}
		}

		/*
		for(i = 0; i < m; i++)
		{
			printf("%d %d\n", count[i], r[i]);
		}
		*/

		for(i = 0; i < m; i++)
		{
			if(count[i] < r[i])
			{
				break;
			}
		}
		if(i < m)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}

	return 0;
}
