#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	char s[10];
	int n, i, j;
	int ti;

	ti = 0;
	while(scanf("%s", s) == 1 && s[0] != '@'){
		scanf("%d", &n);

		++ti;
		if(ti > 1){
			putchar('\n');
		}

		if(n == 1){
			printf("%c\n", s[0]);
			continue;
		}

		for(i = 0; i < n - 1; ++i){
			putchar(' ');
		}
		putchar(s[0]);
		putchar('\n');
		for(i = 1; i < n - 1; ++i){
			for(j = 0; j < n - 1 - i; ++j){
				putchar(' ');
			}
			putchar(s[0]);
			for(j = 0; j < 2 * i - 1; ++j){
				putchar(' ');
			}
			putchar(s[0]);
			putchar('\n');
		}

		for(i = 0; i < 2 * n - 1; ++i){
			putchar(s[0]);
		}
		putchar('\n');
	}

	return 0;
}
