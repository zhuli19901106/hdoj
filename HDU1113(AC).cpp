#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

typedef char ElementType;
void InsertionSort(ElementType a[], int n)
{
	int i;
	int j;
	ElementType tmp;

	for(i = 1; i < n; i++)
	{
		tmp = a[i];
		for(j = i; j > 0 && tmp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}

int main()
{
	int i;
	int j;
	int tmp;
	int dictcount;
	int indices[200];
	int found;
	char word[10];
	char dict[200][10];
	char sorteddict[200][10];

	dictcount = 0;
	while(1)
	{
		gets(dict[dictcount]);

		if(strcmp(dict[dictcount], "XXXXXX") == 0)
		{
			break;
		}
		else
		{
			strcpy(sorteddict[dictcount], dict[dictcount]);
			InsertionSort(sorteddict[dictcount], strlen(sorteddict[dictcount]));
			dictcount++;
		}
	}

	for(i = 0; i < dictcount; i++)
	{
		indices[i] = i;
	}

	for(i = 1; i < dictcount; i++)
	{
		tmp = indices[i];
		for(j = i; j > 0 && strcmp(dict[tmp], dict[indices[j - 1]]) < 0; j--)
		{
			indices[j] = indices[j - 1];
		}
		indices[j] = tmp;
	}

	while(1)
	{
		gets(word);

		if(strcmp(word, "XXXXXX") == 0)
		{
			break;
		}

		InsertionSort(word, strlen(word));
		found = 0;
		for(i = 0; i < dictcount; i++)
		{
			if(strcmp(word, sorteddict[indices[i]]) == 0)
			{
				puts(dict[indices[i]]);
				if(found == 0)
				{
					found = 1;
				}
			}
		}

		if(found == 0)
		{
			puts("NOT A VALID WORD");
		}
		puts("******");
	}

	return 0;
}
