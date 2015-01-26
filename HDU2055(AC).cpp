#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int f(char ch)
{
	if(ch >= 'A' && ch <= 'Z'){
		return +(ch - 'A' + 1);
	}else if(ch >= 'a' && ch <= 'z'){
		return -(ch - 'a' + 1);
	}
}

int main()
{
	int t, ti, y;
	char s[10];

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s%d", s, &y);
			printf("%d\n", y + f(s[0]));
		}
	}

	return 0;
}
