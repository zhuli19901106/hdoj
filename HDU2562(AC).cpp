#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[100], ch;
	int len, i;
	int n, ni;

	while (scanf("%d", &n) == 1) {
		for (ni = 0; ni < n; ++ni) {
			scanf("%s", s);
			len = strlen(s);
			for (i = 0; i < len; i += 2) {
				ch = s[i];
				s[i] = s[i + 1];
				s[i + 1] = ch;
			}
			puts(s);
		}
	}

	return 0;
}