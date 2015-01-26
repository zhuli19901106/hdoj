#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[200];
char maxc;
int na, ne, ni, no, nu;

int main()
{
	int i;
	int t, ti;

	while(gets(s) != NULL && sscanf(s, "%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				printf("\n");
			}

			gets(s);
			na = ne = ni = no = nu = 0;
			for(i = 0; s[i]; ++i){
				if(s[i] == 'a'){
					++na;
				}else if(s[i] == 'e'){
					++ne;
				}else if(s[i] == 'i'){
					++ni;
				}else if(s[i] == 'o'){
					++no;
				}else if(s[i] == 'u'){
					++nu;
				}
			}

			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", na, ne, ni, no, nu);
		}
	}

	return 0;
}
