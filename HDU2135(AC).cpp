#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char a[20][20];
char b[20][20];
char s[20];
int n;
int m;

int main()
{
	int i, j;

	while(gets(s) != NULL && sscanf(s, "%d%d", &n, &m) == 2){
		if(m >= 0){
			m = m % 4;
		}else{
			m = (4 - (4 - m) % 4) % 4;
		}

		for(i = 0; i < n; ++i){
			gets(s);
			for(j = 0; j < n; ++j){
				a[i][j] = s[j];
			}
		}

		if(m == 0){
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					b[i][j] = a[i][j];
				}
			}
		}else if(m == 1){
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					b[i][j] = a[n - 1 - j][i];
				}
			}
		}else if(m == 2){
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					b[i][j] = a[n - 1 - i][n - 1 - j];
				}
			}
		}else{
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					b[i][j] = a[j][n - 1 - i];
				}
			}
		}
		for(i = 0; i < n; ++i){
			b[i][n] = 0;
		}
		for(i = 0; i < n; ++i){
			puts(b[i]);
		}
	}

	return 0;
}
