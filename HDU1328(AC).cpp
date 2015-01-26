#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i;
	int j;
	int n;
	int len;
	char str[1000];

	gets(str);
	sscanf(str, "%d", &n);
	for(i = 0; i < n; i++)
	{
		gets(str);
		len = strlen(str);
		for(j = 0; j < len; j++)
		{
			if(str[j] >= 'A' && str[j] <= 'Z')
			{
				str[j] = (str[j] - 'A' + 1) % 26 + 'A';
			}
		}

		printf("String #%d\n", i + 1);
		puts(str);
		puts("");
	}

	return 0;
}
