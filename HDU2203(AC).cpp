#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


char a[200010], b[100005], c[100005];
int main()
{
	while(scanf("%s%s", c, b) == 2){
		a[0] = 0;
		strcat(a, c);
		strcat(a, c);
		if(strstr(a, b) != NULL){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
