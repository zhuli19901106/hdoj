#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100];
int n;

int main()
{
	int ni, i;

	while(gets(s) != NULL && sscanf(s, "%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			gets(s);
			if(!(s[0] >= 'a' && s[0] <= 'z') && !(s[0] >= 'A' && s[0] <= 'Z') && !(s[0] == '_')){
				printf("no\n");
				continue;
			}
			for(i = 1; s[i]; ++i){
				if(!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] == '_') && !(s[i] >= '0' && s[i] <= '9')){
					break;
				}
			}

			if(s[i]){
				printf("no\n");
			}else{
				printf("yes\n");
			}
		}
	}

	return 0;
}
