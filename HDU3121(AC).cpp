#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i;
	int j;
	int k;
	int n;
	int len;
	char buffer[100];
	char ch;

	gets(buffer);
	sscanf(buffer, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(buffer);
		len = strlen(buffer);
		j = 0;
		k = len - 1;
		while(j < k)
		{
			ch = buffer[j];
			buffer[j] = buffer[k];
			buffer[k] = ch;
			j++;
			k--;
		}

		puts(buffer);
	}

	return 0;
}
