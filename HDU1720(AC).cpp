#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a, b;

int main()
{
	while(scanf("%x%x", &a, &b) == 2){
		printf("%d\n", a + b);
	}

	return 0;
}
