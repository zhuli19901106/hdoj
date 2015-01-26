#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[1005], t[1005];
	int ls, lt;
	int c, i, j;

	while(scanf("%s", s) == 1 && s[0] != '#'){
		scanf("%s", t);
		ls = strlen(s);
		lt = strlen(t);

		c = 0;
		i = 0;
		while(i + lt <= ls){
			for(j = 0; j < lt; ++j){
				if(s[i + j] != t[j]){
					break;
				}
			}
			if(j == lt){
				++c;
				i = i + lt;
			}else{
				++i;
			}
		}

		printf("%d\n", c);
	}

	return 0;
}
