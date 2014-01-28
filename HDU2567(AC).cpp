#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s1[105];
	char s2[105];
	int len;
	int i;
	int c, ci;

	while (gets(s1) && sscanf(s1, "%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			gets(s1);
			gets(s2);
			len = strlen(s1);
			for (i = 0; i < len / 2; ++i) {
				putchar(s1[i]);
			}
			printf("%s", s2);
			for (i = len / 2; i < len; ++i) {
				putchar(s1[i]);
			}
			putchar('\n');
		}
	}

	return 0;
}