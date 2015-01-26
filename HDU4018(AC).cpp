#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1000];
int left, right;

int main()
{
	int len;
	int t, ti;

	while(gets(s) != NULL && sscanf(s, "%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			gets(s);
			len = strlen(s);
			left = 0;
			while(!(s[left] == ':' && s[left + 1] == '/' && s[left + 2] == '/')){
				++left;
			}
			right = left + 3;
			while(right < len && s[right] != '/' && s[right] != ':'){
				++right;
			}			
			s[right] = 0;
			printf("Case #%d: ", ti);
			puts(s + left + 3);
		}
	}

	return 0;
}
