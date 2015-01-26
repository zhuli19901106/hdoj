#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int find(int a[], int n, int key)
{
	int i;

	for(i = 1; i <= n; i++)
	{
		if(a[i] ==key)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int i;
	int j;
	int n;
	int num[51];
	int inv[51];
	int t;
	int pos;
	char ch[2];
	char line[1000];

	while(1)
	{
		gets(line);
		sscanf(line, "%d", &n);
		if(n == 0)
		{
			break;
		}

		scanf("%s", ch);
		if(ch[0] == 'P')
		{
			for(i = 1; i <= n; i++)	
			{
				scanf("%d", &num[i]);
				if(i > 1)
				{
					t = 0;
					for(j = 1; j < i; j++)
					{
						if(num[j] > num[i])
						{
							t++;
						}
					}
					inv[num[i]] = t;
				}
				else
				{
					inv[num[i]] = 0;
				}
			}
			getchar();

			for(i = 1; i <= n; i++)
			{
				if(i == 1)
				{
					printf("%d", inv[i]);
				}
				else
				{
					printf(" %d", inv[i]);
				}
			}
			printf("\n");
		}
		else if(ch[0] == 'I')
		{
			for(i = 1; i <= n; i++)
			{
				scanf("%d", &inv[i]);
				num[i] = i;
			}
			getchar();

			for(i = 1; i <= n; i++)
			{
				t = 0;
				pos = find(num, n, i);
				while(t < inv[i])
				{
					for(j = pos + 1; num[pos] >= num[j] && j <= n; j++)
					{
					}
					if(j <= n)
					{
						swap(&num[pos], &num[j]);
					}
					t++;
					pos = j;
				}
			}
			
			for(i = 1; i <= n; i++)
			{
				if(i == 1)
				{
					printf("%d", num[i]);
				}
				else
				{
					printf(" %d", num[i]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
