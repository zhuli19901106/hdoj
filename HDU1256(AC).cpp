#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int ti, t;
	char s[5];
	int n;
	int i, j;
	int hx1, hx2, vy1, vy2;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				putchar('\n');
			}
			scanf("%s%d", s, &n);
			vy2 = (n - 3 + 1) / 2;
			vy1 = (n - 3) - vy2;
			hx1 = n / 6 + 1;
			hx2 = vy2;
			//5 -> 1
			//6 -> 2
			//11 -> 2

			for(i = 0; i < hx1; ++i){
				putchar(' ');
			}
			for(i = 0; i < hx2; ++i){
				putchar(s[0]);
			}
			putchar('\n');

			for(i = 0; i < vy1; ++i){
				for(j = 0; j < hx1; ++j){
					putchar(s[0]);
				}
				for(j = 0; j < hx2; ++j){
					putchar(' ');
				}
				for(j = 0; j < hx1; ++j){
					putchar(s[0]);
				}
				putchar('\n');
			}

			for(i = 0; i < hx1; ++i){
				putchar(' ');
			}
			for(i = 0; i < hx2; ++i){
				putchar(s[0]);
			}
			putchar('\n');

			for(i = 0; i < vy2; ++i){
				for(j = 0; j < hx1; ++j){
					putchar(s[0]);
				}
				for(j = 0; j < hx2; ++j){
					putchar(' ');
				}
				for(j = 0; j < hx1; ++j){
					putchar(s[0]);
				}
				putchar('\n');
			}

			for(i = 0; i < hx1; ++i){
				putchar(' ');
			}
			for(i = 0; i < hx2; ++i){
				putchar(s[0]);
			}
			putchar('\n');
		}
	}

	return 0;
}
