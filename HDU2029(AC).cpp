#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
char s[1000];

int main()
{
	int len, i;
	int ni;

	while(gets(s) != NULL && sscanf(s, "%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			gets(s);
			len = strlen(s);
			i = 0;
			while(i < len - 1 - i){
				if(s[i] != s[len - 1 - i]){
					break;
				}else{
					++i;
				}
			}

			if(i >= len - 1 - i){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}

	return 0;
}
