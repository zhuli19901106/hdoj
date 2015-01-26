#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int len;
	int i;
	int QuickSum;
	char line[1000];

	while(1)
	{
		gets(line);
		if(strcmp(line, "#") == 0)
		{
			break;
		}

		QuickSum = 0;
		len = strlen(line);
		for(i = 0; i < len; i++)
		{
			if(line[i] >= 'A' && line[i] <= 'Z')
			{
				QuickSum = QuickSum + (line[i] - 'A' + 1) * (i + 1);
			}
		}

		printf("%d\n", QuickSum);
	}

	return 0;
}
