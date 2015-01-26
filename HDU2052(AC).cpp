#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	int i, j;

	while(scanf("%d%d", &m, &n) == 2){
		putchar('+');
		for(i = 0; i < m; ++i){
			putchar('-');
		}
		putchar('+');
		putchar('\n');

		for(i = 0; i < n; ++i){
			putchar('|');
			for(j = 0; j < m; ++j){
				putchar(' ');
			}
			putchar('|');
			putchar('\n');
		}

		putchar('+');
		for(i = 0; i < m; ++i){
			putchar('-');
		}
		putchar('+');
		putchar('\n');

		putchar('\n');
	}

	return 0;
}
