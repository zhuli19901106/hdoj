#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

char getreverse(char ch)
{
	switch(ch)
	{
	case 'A':
		return 'A';
	case 'E':
		return '3';
	case 'H':
		return 'H';
	case 'I':
		return 'I';
	case 'J':
		return 'L';
	case 'L':
		return 'J';
	case 'M':
		return 'M';
	case 'O':
		return 'O';
	case 'S':
		return '2';
	case 'T':
		return 'T';
	case 'U':
		return 'U';
	case 'V':
		return 'V';
	case 'W':
		return 'W';
	case 'X':
		return 'X';
	case 'Y':
		return 'Y';
	case 'Z':
		return '5';
	case '1':
		return '1';
	case '2':
		return 'S';
	case '3':
		return 'E';
	case '5':
		return 'Z';
	case '8':
		return '8';
	default:
		return 0;
	}
}

int main()
{
	int i;
	int j;
	int palidrome;
	int mirror;
	int len;
	char buffer[1000];

	while(1)
	{
		if(scanf("%s", buffer) != 1)
		{
			break;
		}

		len = strlen(buffer);
		i = 0;
		j = len - 1;
		while(i < j)
		{
			if(buffer[i] != buffer[j])
			{
				break;
			}
			else
			{
				i++;
				j--;
			}
		}
		if(i < j)
		{
			palidrome = 0;
		}
		else
		{
			palidrome = 1;
		}

		i = 0;
		j = len - 1;
		while(i < j)
		{
			if(buffer[i] != getreverse(buffer[j]) || buffer[j] != getreverse(buffer[i]))
			{
				break;
			}
			else
			{
				i++;
				j--;
			}
		}

		if(i < j)
		{
			mirror = 0;
		}
		else
		{
			if(len % 2 == 0)
			{
				mirror = 1;
			}
			else
			{
				if(buffer[(len - 1) / 2] == getreverse(buffer[(len - 1) / 2]))
				{
					mirror = 1;
				}
				else
				{
					mirror = 0;
				}
			}
		}

		if(palidrome == 0 && mirror == 0)
		{
			printf("%s -- is not a palindrome.\n", buffer);
		}
		else if(palidrome == 0 && mirror == 1)
		{
			printf("%s -- is a mirrored string.\n", buffer);
		}
		else if(palidrome == 1 && mirror == 0)
		{
			printf("%s -- is a regular palindrome.\n", buffer);
		}
		else if(palidrome == 1 && mirror == 1)
		{
			printf("%s -- is a mirrored palindrome.\n", buffer);
		}
		printf("\n");
	}

	return 0;
}
