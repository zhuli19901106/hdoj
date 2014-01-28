#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int main()
{
	char s[3005];
	char w[100];
	char t[100];
	map<string, string> mm;
	map<string, string>::iterator mit;
	int len;
	int i, j;
	string sw, st;

	mm.clear();
	gets(s);
	while (gets(s) != NULL && strcmp(s, "END") != 0) {
		sscanf(s, "%s%s", w, t);
		mm[string(t)] = string(w);
	}

	gets(s);
	while (gets(s) != NULL && strcmp(s, "END") != 0) {
		len = strlen(s);
		i = 0;
		while (true) {
			while (i < len && !isalpha(s[i])) {
				putchar(s[i++]);
			}
			if (i >= len) {
				break;
			}
			j = 0;
			while (i < len && isalpha(s[i])) {
				t[j++] = s[i++];
			}
			t[j] = 0;
			st = string(t);
			mit = mm.find(st);
			if (mit != mm.end()) {
				printf("%s", (mit->second).c_str());
			} else {
				printf("%s", t);
			}
			if (i >= len) {
				break;
			}
		}
		putchar('\n');
	}

	return 0;
}