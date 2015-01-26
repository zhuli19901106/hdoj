#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i;
	int j;
	int len;
	int n;
	int count;
	int a[16];
	int appear[100];
	char line[1000];

	while(1)
	{
		gets(line);
		if(strcmp(line, "-1") == 0)
		{
			break;
		}
		else
		{
			len = strlen(line);
			n = 1;
			for(i = 0; i < len; i++)
			{
				if(line[i] == ' ')
				{
					n++;
				}
			}

			for(i = 1; i <= 99; i++)
			{
				appear[i] = 0;
			}

			sscanf(line, "%d", &a[0]);
			appear[a[0]] = 1;
			i = 1;
			j = 0;
			count = 0;
			while(i < n)
			{
				while(line[j] != ' ')
				{
					j++;
				}
				j++;
				sscanf(line + j, "%d", &a[i]);
				appear[a[i]] = 1;
				i++;
			}

			for(i = 0; i < n; i++)
			{
				if(a[i] * 2 >= 1 && a[i] * 2 <= 99)
				{
					if(appear[a[i] * 2] == 1)
					{
						count++;
					}
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
