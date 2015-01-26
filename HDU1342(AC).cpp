#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	int a[14];
	int k = 6;
	int i;
	int s[10];
	int sc;
	int tmp;
	int casecount;

	casecount = 0;
	while(true)
	{
		if(scanf("%d", &n) != 1)
		{
			break;
		}

		if(n == 0)
		{
			break;
		}

		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		if(casecount > 0)
		{
			printf("\n");
		}

		sc = 0;
		for(i = 0; i < 6; i++)
		{
			s[sc] = i;
			sc++;
		}

		while(true)
		{
			for(i = 0; i < 6; i++)
			{
				if(i == 0)
				{
					printf("%d", a[s[i]]);
				}
				else
				{
					printf(" %d", a[s[i]]);
				}
			}
			printf("\n");

			while(sc > 0 && s[sc - 1] == sc + n - 7)
			{
				sc--;
			}

			if(sc == 0)
			{
				break;
			}
			else
			{
				s[sc - 1]++;
				tmp = s[sc - 1];
				while(sc < 6)
				{
					s[sc] = tmp + 1;
					tmp = s[sc];
					sc++;
				}
			}
		}

		casecount++;
	}

	return 0;
}
