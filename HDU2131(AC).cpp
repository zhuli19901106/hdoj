#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[500];
int count;
int len;
char let;

int main()
{
	int i;

	while(scanf("%s", s) == 1){
		let = s[0];
		scanf("%s", s);
		if(let >= 'A' && let <= 'Z'){
			let = let - 'A' + 'a';
		}
		len = strlen(s);
		count = 0;
		for(i = 0; i < len; ++i){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] = s[i] - 'A' + 'a';
			}
			if(s[i] == let){
				++count;
			}
		}
		printf("%.5f\n", 1.0 * count / len);
	}

	return 0;
}
