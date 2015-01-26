#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i;
	int len;
	char buffer[1000];

	while(1)
	{
		gets(buffer);
		if(strcmp(buffer, "ENDOFINPUT") == 0)
		{
			break;
		}
		gets(buffer);
		len = strlen(buffer);
		for(i = 0; i < len; i++)
		{
			if(buffer[i] >= 'A' && buffer[i] <= 'Z')
			{
				buffer[i] = (buffer[i] - 'A' - 5 + 26) % 26 + 'A';
			}
		}
		puts(buffer);
		gets(buffer);
	}

	return 0;
}
