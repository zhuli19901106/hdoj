#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i;
	int a, b, n, loop_len;
	int v[100];
	
	while(true){
		if(scanf("%d%d%d", &a, &b, &n) != 3){
			break;
		}else if(a == 0 && b == 0 && n == 0){
			break;
		}

		v[1] = 1;
		v[2] = 1;
		for(i = 3; i <= 49; ++i){
			v[i] = (a * v[i - 1] + b * v[i - 2]) % 7;
			if(v[i] == 1 && v[i - 1] == 1){
				break;
			}
		}
		loop_len = i - 2;
		printf("%d\n", v[(n - 1) % loop_len + 1]);
	}
	
	return 0;
}
