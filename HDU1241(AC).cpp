#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int globalcounter;
int flood(int field[][102], int m, int n, int x, int y)
{
	if(field[x][y] != -1)
	{
		return -1;
	}
	else
	{
		field[x][y] = globalcounter;
		if(x > 1)
		{
			if(field[x - 1][y] == -1)
			{
				flood(field, m, n, x - 1, y);
			}
			if(y > 1 && field[x - 1][y - 1] == -1)
			{
				flood(field, m, n, x - 1, y - 1);
			}
			if(y < n && field[x - 1][y + 1] == -1)
			{
				flood(field, m, n, x - 1, y + 1);
			}
		}
		if(x < m)
		{
			if(field[x + 1][y] == -1)
			{
				flood(field, m, n, x + 1, y);
			}
			if(y > 1 && field[x + 1][y - 1] == -1)
			{
				flood(field, m, n, x + 1, y - 1);
			}
			if(y < n && field[x + 1][y + 1] == -1)
			{
				flood(field, m, n, x + 1, y + 1);
			}
		}
		if(y > 1 && field[x][y - 1] == -1)
		{
			flood(field, m, n, x, y - 1);
		}
		if(y < n && field[x][y + 1] == -1)
		{
			flood(field, m, n, x, y + 1);
		}

		return 0;
	}
}

int main()
{
	int i;
	int j;
	char buffer[1000];
	int m;
	int n;
	int field[102][102];

	while(1)
	{
		gets(buffer);
		sscanf(buffer, "%d%d", &m, &n);

		if(m == 0 && n == 0)
		{
			break;
		}

		for(i = 0; i <= m + 1; i++)
		{
			for(j = 0; j <= n + 1; j++)
			{
				field[i][j] = 0;
			}
		}

		for(i = 1; i <= m; i++)
		{
			gets(buffer);
			for(j = 1; j <= n; j++)
			{
				if(buffer[j - 1] == '@')
				{
					field[i][j] = -1;
				}
			}
		}

		globalcounter = 1;
		for(i = 1; i <= m; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(flood(field, m, n, i, j) == 0)
				{
					globalcounter++;
				}
			}
		}
		globalcounter--;

		printf("%d\n", globalcounter);
	}

	return 0;
}
