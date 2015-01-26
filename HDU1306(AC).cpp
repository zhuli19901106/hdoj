#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	if(a == b)
	{
		return a;
	}
	else
	{
		while(true)
		{
			if(a > b)
			{
				if(a % b == 0)
				{
					return b;
				}
				else
				{
					a = a % b;
				}
			}
			else
			{
				if(b % a == 0)
				{
					return a;
				}
				else
				{
					b = b % a;
				}
			}
		}
	}
}

void approximate(char s1[], char s2[], int result[])
{
	int i, j;

	int len1;
	int len2;
	int count;
	int maxcount;
	int tmp;

	len1 = strlen(s1);
	len2 = strlen(s2);

	if(len1 > len2)
	{
		approximate(s2, s1, result);
	}
	else
	{
		maxcount = 0;
		for(i = 1; i <= len1 - 1; i++)
		{
			count = 0;
			for(j = 0; j < i; j++)
			{
				if(s1[j + len1 - i] == s2[j])
				{
					count++;
				}
			}

			if(count > maxcount)
			{
				maxcount = count;
			}
		}

		count = 0;
		for(i = 0; i <= len2 - len1; i++)
		{
			count = 0;
			for(j = 0; j < len1; j++)
			{
				if(s1[j] == s2[j + i])
				{
					count++;
				}
			}

			if(count > maxcount)
			{
				maxcount = count;
			}
		}

		for(i = 1; i <= len1 - 1; i++)
		{
			count = 0;
			for(j = 0; j < i; j++)
			{
				if(s1[j] == s2[j + len2 - i])
				{
					count++;
				}
			}

			if(count > maxcount)
			{
				maxcount = count;
			}
		}

		result[0] = 2 * maxcount;
		result[1] = len1 + len2;
		if(result[0] > 0 && result[1] > 0)
		{
			tmp = gcd(result[0], result[1]);
			result[0] /= tmp;
			result[1] /= tmp;
		}
	}
}

int main()
{
	char s1[1000];
	char s2[1000];
	char buffer[1000];
	int result[2];

	while(true)
	{
		if(gets(buffer) == NULL)
		{
			break;
		}

		if(strcmp(buffer, "-1") == 0)
		{
			break;
		}

		sscanf(buffer, "%s%s", s1, s2);
		approximate(s1, s2, result);

		printf("appx(%s,%s) = ", s1, s2);
		if(result[0] == 0)
		{
			printf("0\n");
		}
		else if(result[0] == result[1])
		{
			printf("1\n");
		}
		else
		{
			printf("%d/%d\n", result[0], result[1]);
		}
	}

	return 0;
}
