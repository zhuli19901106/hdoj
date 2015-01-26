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
	int ni;
	char buffer[10050];

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		for(ni = 0; ni < n; ni++)
		{
			scanf("%s", buffer);
			len = strlen(buffer);

			i = 0;
			j = i + 1;
			while(i < len)
			{
				while(buffer[i] == buffer[j])
				{
					j++;
				}
				if(j - i > 1)
				{
					printf("%d%c", j - i, buffer[i]);
					i = j;
					j = i + 1;
				}
				else if(j - i == 1)
				{
					printf("%c", buffer[i]);
					i = j;
					j = i + 1;
				}
			}

			printf("\n");
		}
	}

	return 0;
}
