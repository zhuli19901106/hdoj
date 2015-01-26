#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int getdigit(const char ch)
{
	if(ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if(ch >= 'A' && ch <= 'F')
	{
		return ch - 'A' + 10;
	}
	else
	{
		return -1;
	}
}

char getdigitchar(int d)
{
	if(d >= 0 && d <= 9)
	{
		return d + '0';
	}
	else if(d >= 10 && d <= 15)
	{
		return d - 10 + 'A';
	}
	else
	{
		return 0;
	}
}

void reverse(char buffer[])
{
	int i;
	int j;
	int len;
	char ch;

	len = strlen(buffer);
	i = 0;
	j = len - 1;
	while(i < j)
	{
		ch = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = ch;
		i++;
		j--;
	}
}

int main()
{
	int i;
	int j;
	char buffer[1000];
	char digits[1000];
	int amount;
	int bounds[17] = {
		0, 0
	};
	int b1;
	int b2;
	int len;

	for(i = 2; i <= 16; i++)
	{
		bounds[i] = 1;
		for(j = 0; j < 7; j++)
		{
			bounds[i] *= i;
		}
		bounds[i]--;
	}

	while(gets(buffer) != NULL)
	{
		sscanf(buffer, "%s%d%d", digits, &b1, &b2);
		amount = 0;
		len = strlen(digits);
		for(i = 0; i < len; i++)
		{
			amount *= b1;
			amount += getdigit(digits[i]);
		}

		if(amount > bounds[b2])
		{
			printf("%7s\n", "ERROR");
		}
		else if(amount == 0)
		{
			printf("%7s\n", "0");
		}
		else
		{
			i = 0;
			while(amount > 0)
			{
				digits[i] = getdigitchar(amount % b2);
				amount -= amount % b2;
				amount = amount / b2;
				i++;
			}
			digits[i] = 0;
			reverse(digits);
			printf("%7s\n", digits);
		}
	}

	return 0;
}
