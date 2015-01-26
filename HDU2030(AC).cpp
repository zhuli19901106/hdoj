#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[1000];
int res;
int n, ni;

int main()
{
	int i;

	while(gets(s) != NULL && sscanf(s, "%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			gets(s);
			res = 0;
			for(i = 0; s[i]; ++i){
				if(s[i] < 0){
					++res;
				}
			}
			res /= 2;
			printf("%d\n", res);
		}
	}

	return 0;
}
