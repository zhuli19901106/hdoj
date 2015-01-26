#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100005;
__int64 p;
int a[MAXN];

int main()
{
	__int64 i;

	while(scanf("%I64d", &p) == 1 && p){
		if(p == 2){
			printf("Impossible\n");
		}else{
			for(i = 1; i < p; ++i){
				a[i] = 1;
			}
			for(i = 1; i < p; ++i){
				a[i * i % p] = 0;
			}
			for(i = 1; i < p; ++i){
				putchar(a[i] + '0');
			}
			putchar('\n');
		}
	}

	return 0;
}
