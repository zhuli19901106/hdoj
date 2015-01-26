#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[1000];
	int t, ti;
	int i, j;
	int ll, rr;
	char tmp;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s", s);
			if(s[0] == '-' || s[0] == '+'){
				ll = 1;
			}else{
				ll = 0;
			}
			rr = strlen(s) - 1;
			while(rr > 0 && s[rr] == '0'){
				--rr;
			}
			i = ll;
			j = rr;
			while(i < j){
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				++i;
				--j;
			}
			
			puts(s);
		}
	}

	return 0;
}
