#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	char s[2000];
	int i;

	while(gets(s) != NULL){
		for(i = 0; s[i]; ++i){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] = s[i] - 'A' + 'a';
			}
		}
		puts(s);
	}

	return 0;
}
