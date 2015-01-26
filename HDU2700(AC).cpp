#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[1000];
	int len;
	int i, c;

	while(scanf("%s", s) == 1 && strcmp(s, "#")){
		len = strlen(s);
		c = 0;
		for(i = 0; i < len - 1; ++i){
			if(s[i] == '1'){
				c = !c;
			}
		}

		if(s[len - 1] == 'e'){
			if(c){
				s[len - 1] = '1';
			}else{
				s[len - 1] = '0';
			}
		}else if(s[len - 1] == 'o'){
			if(c){
				s[len - 1] = '0';
			}else{
				s[len - 1] = '1';
			}
		}

		printf("%s\n", s);
	}

	return 0;
}
