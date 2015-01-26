#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, c;
	const int h = 168;
	
	while(true){
		if(scanf("%d%d%d", &a, &b, &c) != 3){
			break;
		}
		if(a <= h){
			printf("CRASH %d\n", a);
		}else if(b <= h){
			printf("CRASH %d\n", b);
		}else if(c <= h){
			printf("CRASH %d\n", c);
		}else{
			printf("NO CRASH\n");
		}
	}
	
	return 0;
}
