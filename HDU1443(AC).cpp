#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/*
int main()
{
	int f[100];
	int n, c, cc, left_cc;
	int m, i, this_i;
	
	while(scanf("%d", &n) == 1 && n){
		n *= 2;
		for(m = n / 2 + 1; ; ++m){
			if(m % (n / 2 + 1) != 0 && m % (n / 2 + 1) != 1){
				continue;
			}
			memset(f, 0, 100 * sizeof(int));
			cc = 0;
			left_cc = n;
			i = 0;
			while(cc < n / 2){
				c = 1;
				if(!(left_cc = m % (n - cc))){
					left_cc = n - cc;
				}
				while(true){
					if(!f[i]){
						if(c == left_cc){
							this_i = i;
							f[i] = 1;
							i = (i + 1) % n;
							break;
						}else{
							++c;
							i = (i + 1) % n;
						}
					}else{
						i = (i + 1) % n;
					}
				}
				if(this_i >= 0 && this_i <= n / 2 - 1){
					break;
				}else{
					--left_cc;
					++cc;
				}
			}
			if(cc == n / 2){
				break;
			}
		}
		printf("%d\n", m);
	}
	
	return 0;
}
*/

int main()
{
	int a[15] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720};
	int n;

	while(scanf("%d", &n) == 1 && n){
		printf("%d\n", a[n]);
	}

	return 0;
}
