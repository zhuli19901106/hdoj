#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[2000];
int a[26];
int b[26];

int main()
{
	int i, j;
	int len;

	gets(s);
	len = strlen(s);
	memset(a, 0, 26 * sizeof(int));
	memset(b, 0, 26 * sizeof(int));
	for(i = 0; i < len; ++i){
		a[i] = s[i] - 'A';
		b[s[i] - 'A'] = 1;
	}

	j = 0;
	for(i = 25; i >= len; --i){
		while(b[j]){
			++j;
		}
		a[i] = j;
		b[j] = 1;
	}

	for(i = 0; i < 26; ++i){
		b[a[i]] = i;
	}

	while(gets(s) != NULL){
		len = strlen(s);
		for(i = 0; i < len; ++i){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] = b[s[i] - 'A'] + 'A';
			}else if(s[i] >= 'a' && s[i] <= 'z'){
				s[i] = b[s[i] - 'a'] + 'a';
			}
		}
		puts(s);
	}

	return 0;
}
