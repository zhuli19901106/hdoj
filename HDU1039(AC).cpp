#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int isvowel(const char ch)
{
	if(ch >= 'a' && ch <= 'z')
	{
		switch(ch)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
		default:
			return 0;
		}
	}

	return 0;
}

int isconsonant(const char ch)
{
	if(ch >= 'a' && ch <= 'z')
	{
		if(!isvowel(ch))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i;
	int len;
	int acceptable;
	int hasvowel;
	int vowels;
	int consonants;
	char buffer[1000];

	while(1)
	{
		gets(buffer);
		if(strcmp(buffer, "end") == 0)
		{
			break;
		}

		len = strlen(buffer);
		acceptable = 1;
		vowels = 0;
		consonants = 0;
		hasvowel = 0;
		if(isvowel(buffer[0]))
		{
			hasvowel = 1;
			vowels = 1;
		}
		else if(isconsonant(buffer[0]))
		{
			consonants = 1;
		}

		for(i = 1; acceptable == 1 && i < len; i++)
		{
			if(buffer[i] == buffer[i - 1])
			{
				if(buffer[i] != 'e' && buffer[i] != 'o')
				{
					acceptable = 0;
				}
			}

			if(isvowel(buffer[i]))
			{
				if(hasvowel == 0)
				{
					hasvowel = 1;
				}

				if(vowels > 0)
				{
					vowels++;
					if(vowels == 3)
					{
						acceptable = 0;
					}
				}
				else
				{
					vowels++;
				}

				if(consonants > 0)
				{
					consonants = 0;
				}
			}
			else if(isconsonant(buffer[i]))
			{
				if(consonants > 0)
				{
					consonants++;
					if(consonants == 3)
					{
						acceptable = 0;
					}
				}
				else
				{
					consonants++;
				}

				if(vowels > 0)
				{
					vowels = 0;
				}
			}
		}

		if(hasvowel == 0)
		{
			acceptable = 0;
		}

		if(acceptable == 1)
		{
			printf("<%s> is acceptable.\n", buffer);
		}
		else
		{
			printf("<%s> is not acceptable.\n", buffer);
		}
	}

	return 0;
}
