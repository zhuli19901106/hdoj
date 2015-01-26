#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[100];
	int len;
	int i;
	int j;
	int n;

	while(scanf("%s%d", s, &n) == 2){
		if(n < 0){
			n = (8 - (8 - n) % 8) % 8;
		}else{
			n = n % 8;
		}

		len = strlen(s);
		switch(n){
		case 0:
			for(i = 0; i < len; ++i){
				putchar(s[i]);
			}
			putchar('\n');
			break;
		case 1:
			for(i = len - 1; i >= 0; --i){
				for(j = 0; j < i; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		case 2:
			for(i = len - 1; i >= 0; --i){
				for(j = 0; j < len / 2; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		case 3:
			for(i = len - 1; i >= 0; --i){
				for(j = 0; j < len - 1 - i; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		case 4:
			for(i = len - 1; i >= 0; --i){
				putchar(s[i]);
			}
			putchar('\n');
			break;
		case 5:
			for(i = 0; i < len; ++i){
				for(j = 0; j < len - 1 - i; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		case 6:
			for(i = 0; i < len; ++i){
				for(j = 0; j < len / 2; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		case 7:
			for(i = 0; i < len; ++i){
				for(j = 0; j < i; ++j){
					putchar(' ');
				}
				putchar(s[i]);
				putchar('\n');
			}
			break;
		}
	}

	return 0;
}
