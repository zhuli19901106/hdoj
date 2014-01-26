#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[200];
	char t[200];
	int i, j, len;
	int c, ci;

	while (gets(s) != NULL && sscanf(s, "%d", &c) == 1) {
		for (ci = 0; ci < c; ++ci) {
			gets(s);
			len = strlen(s);
			i = j = 0;
			while (i < len) {
				while (i < len && s[i] == ' ') {
					++i;
				}
				if (i >= len) {
					break;
				}
				if (s[i] >= 'A' && s[i] <= 'Z') {
					t[j++] = s[i];
				} else if(s[i] >= 'a' && s[i] <= 'z') {
					t[j++] = s[i] - 'a' + 'A';
				}
				while (i < len && s[i] != ' ') {
					++i;
				}
			}
			t[j] = 0;
			puts(t);
		}
	}

	return 0;
}