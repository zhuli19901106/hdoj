#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[100];
char maxc;

int main()
{
	int i;

	while(gets(s) != NULL){
		maxc = s[0];
		for(i = 1; s[i]; ++i){
			if(s[i] > maxc){
				maxc = s[i];
			}
		}
		for(i = 0; s[i]; ++i){
			putchar(s[i]);
			if(s[i] == maxc){
				printf("(max)");
			}
		}
		putchar('\n');
	}

	return 0;
}
