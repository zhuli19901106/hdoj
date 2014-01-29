#include <cstdio>
using namespace std;

int main()
{
	int m1, m2;
	int r1, r2, r3;
	const int MAXN = 205;
	char s[MAXN];
	int i;

	while (scanf("%d%d", &m1, &m2) == 2) {
		scanf("%s", s);
		r1 = r2 = r3 = 0;
		for (i = 0; s[i]; ++i) {
			switch (s[i]) {
			case 'A':
				r1 = m1;
				break;
			case 'B':
				r2 = m2;
				break;
			case 'C':
				m1 = r3;
				break;
			case 'D':
				m2 = r3;
				break;
			case 'E':
				r3 = r1 + r2;
				break;
			case 'F':
				r3 = r1 - r2;
				break;
			}
		}
		printf("%d,%d\n", m1, m2);
	}

	return 0;
}