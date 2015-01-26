#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

char s[100005];
int a[256];

int main()
{
	int i;

	while(gets(s) != NULL){
		for(i = 0; i < 256; ++i){
			a[i] = 0;
		}
		for(i = 0; s[i]; ++i){
			++a[s[i]];
		}
		for(i = 'a'; i <= 'z'; ++i){
			printf("%c:%d\n", i, a[i]);
		}
		printf("\n");
	}

	return 0;
}
