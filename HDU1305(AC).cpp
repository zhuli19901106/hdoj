#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXNUM 100
#define MAXLEN 100

char *codes[MAXNUM];

int prefix(char *s, char *t)
{
	char tmp;
	int lens;
	int lent;

	if(strlen(s) > strlen(t))
	{
		return prefix(t, s);
	}
	else
	{
		lens = strlen(s);
		lent = strlen(t);
		tmp = t[lens];
		t[lens] = 0;
		if(strcmp(s, t) == 0)
		{
			t[lens] = tmp;
			return 1;
		}
		else
		{
			t[lens] = tmp;
			return 0;
		}
	}
}

int main()
{
	int counter;
	int casecounter;
	int i;
	int j;
	char *tmp;

	for(i = 0; i < MAXNUM; i++)
	{
		codes[i] = (char *)malloc(MAXLEN * sizeof(char));
	}

	casecounter = 0;
	while(1)
	{
		casecounter++;
		counter = 0;
		while(1)
		{
			if(gets(codes[counter]) == NULL)
			{
				return 0;
			}
			if(strcmp(codes[counter], "9") == 0)
			{
				break;
			}
			else
			{
				counter++;
			}
		}

		if(counter <= 1)
		{
			printf("Set %d is immediately decodable\n", casecounter);
		}
		else
		{
			for(i = 0; i < counter - 1; i++)
			{
				for(j = i + 1; j < counter; j++)
				{
					if(strcmp(codes[i], codes[j]) > 0)
					{
						tmp = codes[i];
						codes[i] = codes[j];
						codes[j] = tmp;
					}
				}
			}

			for(i = 0; i < counter - 1; i++)
			{
				if(prefix(codes[i], codes[i + 1]))
				{
					break;
				}
			}

			if(i == counter - 1)
			{
				printf("Set %d is immediately decodable\n", casecounter);
			}
			else
			{
				printf("Set %d is not immediately decodable\n", casecounter);
			}
		}
	}

	for(i = 0; i < MAXNUM; i++)
	{
		free(codes[i]);
	}

	return 0;
}
