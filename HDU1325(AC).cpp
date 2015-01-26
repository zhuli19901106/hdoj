#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int involved[10001];
	int ind[10001];
	int outd[10001];
	int in;
	int out;
	int caseno;
	int sum;
	int count1;
	int i;
	bool cycle;
	int nodecount;

	caseno = 1;
	while(true)
	{
		memset(involved, 0, 10001 * sizeof(int));
		memset(ind, 0, 10001 * sizeof(int));
		memset(outd, 0, 10001 * sizeof(int));
		scanf("%d%d", &in, &out);
		if(in < 0 && out < 0)
		{
			break;
		}
		else
		{
			cycle = false;
			if(in == 0 && out == 0)
			{
				printf("Case %d is a tree.\n", caseno);
				caseno++;
				continue;
			}
			else if(in == out)
			{
				cycle = true;
			}

			outd[in]++;
			ind[out]++;
			involved[in] = involved[out] = 1;

			while(true)
			{
				scanf("%d%d", &in, &out);
				if(in == 0 && out == 0)
				{
					break;
				}
				else
				{
					if(in == out)
					{
						cycle = true;
					}
					outd[in]++;
					ind[out]++;
					involved[in] = involved[out] = 1;
				}
			}

			sum = 0;
			count1 = 0;
			nodecount = 0;
			for(i = 1; i < 10001; i++)
			{
				sum += ind[i];
				if(ind[i] == 1)
				{
					count1++;
				}
				if(involved[i] == 1)
				{
					nodecount++;
				}
			}

			if(cycle == true)
			{
				printf("Case %d is not a tree.\n", caseno);
				caseno++;
				continue;
			}
			else if(sum == count1 && count1 == nodecount - 1)
			{
				printf("Case %d is a tree.\n", caseno);
				caseno++;
				continue;
			}
			else
			{
				printf("Case %d is not a tree.\n", caseno);
				caseno++;
				continue;
			}
		}
	}

	return 0;
}
