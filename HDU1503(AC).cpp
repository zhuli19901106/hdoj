#define _CRT_SECURE_NO_WARNINGS
//#define MY_DEBUG
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
char sa[MAXN];
char sb[MAXN];
int la, lb;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int s[MAXN][2];
int sc;
int lcs;

void create_lcs(int i, int j)
{
	if(i <= 0 || j <= 0){
		return;
	}

	if(f[i][j] == 1){
		create_lcs(i - 1, j - 1);
		s[sc][0] = i;
		s[sc][1] = j;
		++sc;
	}else if(f[i][j] == 2){
		create_lcs(i - 1, j);
	}else{
		create_lcs(i, j - 1);
	}
}

int main()
{
	int i, j, k;

	while(scanf("%s%s", sa + 1, sb + 1) == 2){
		memset(a, 0, MAXN * MAXN * sizeof(int));
		memset(f, 0, MAXN * MAXN * sizeof(int));

		la = strlen(sa + 1);
		lb = strlen(sb + 1);

		for(i = 1; i <= la; ++i){
			a[i][0] = 0;
		}
		for(j = 1; j <= lb; ++j){
			a[0][j] = 0;
		}

		for(i = 1; i <= la; ++i){
			for(j = 1; j <= lb; ++j){
				if(sa[i] == sb[j]){
					a[i][j] = a[i - 1][j - 1] + 1;
					f[i][j] = 1;
				}else if(a[i - 1][j] >= a[i][j - 1]){
					a[i][j] = a[i - 1][j];
					f[i][j] = 2;
				}else{
					a[i][j] = a[i][j - 1];
					f[i][j] = 3;
				}
			}
		}
#ifdef MY_DEBUG
		for(i = 1; i <= la; ++i){
			for(j = 1; j <= lb; ++j){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
#endif
		lcs = a[la][lb];

		sc = 0;
		create_lcs(la, lb);

#ifdef MY_DEBUG
		for(i = 0; i < sc; ++i){
			printf("%c", sa[s[i][0]]);
		}
		printf("\n");
		for(i = 0; i < sc; ++i){
			printf("%c", sb[s[i][1]]);
		}
		printf("\n");
#endif
		i = 1;
		j = 1;
		k = 0;
		while(k < sc){
			while(i < s[k][0]){
				putchar(sa[i]);
				++i;
			}
			while(j < s[k][1]){
				putchar(sb[j]);
				++j;
			}
			putchar(sa[s[k][0]]);
			++i;
			++j;
			++k;
		}
		while(i <= la){
			putchar(sa[i]);
			++i;
		}
		while(j <= lb){
			putchar(sb[j]);
			++j;
		}
		putchar('\n');
	}

	return 0;
}
