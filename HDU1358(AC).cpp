#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int next[1000005];
char s[1000005];
int clen;

void get_next(const char pat[], int next[], int lp)
{  
	int i = 0;
	int j = -1;

	next[0] = -1;
	while(i <= lp - 1){
		if(j == -1 || pat[i] == pat[j]){
			++i;
			++j;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}

int main()
{
	int n;
	int ni;
	int i;

	ni = 0;
	while(gets(s), sscanf(s, "%d", &n) == 1 && n){
		++ni;
		gets(s);
		printf("Test case #%d\n", ni);

		memset(next, 0, 1000005 * sizeof(int));
		get_next(s, next, n);
		for(i = 2; i <= n; ++i){
			clen = i - next[i];
			if(i % clen == 0 && i / clen > 1){
				printf("%d %d\n", i, i / clen);
			}
		}

		printf("\n");
	}

	return 0;
}
