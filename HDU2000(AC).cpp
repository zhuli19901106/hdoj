#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	char s[10];

	while(gets(s)){
		sort(s, s + strlen(s));
		printf("%c %c %c\n", s[0], s[1], s[2]);
	}

	return 0;
}
