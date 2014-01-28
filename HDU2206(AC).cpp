#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i, j;
	int tmp;
	int len;
	char s[105];
	char t[105];
	bool suc;

	while (gets(s) != NULL) {
		len = strlen(s);
		suc = true;
		do {
			if (len <= 0) {
				suc = false;
				break;
			}
			for (i = 0; i < len; ++i) {
				if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '.') {
					suc = false;
					break;
				}
			}
			j = 0;
			for (i = 0; i < len; ++i) {
				if (s[i] == '.') {
					++j;
				}
			}
			if (j != 3) {
				suc = false;
				break;
			}
			i = 0;
			while (i < len) {
				j = 0;
				while (i < len  && s[i] != '.') {
					t[j++] = s[i++];
				}
				t[j] = 0;
				if (j < 1 || j > 3) {
					suc = false;
					break;
				}
				sscanf(t, "%d", &tmp);
				if (tmp < 0 || tmp > 255) {
					suc = false;
					break;
				}
				++i;
			}
		} while (0);
		if (suc) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}