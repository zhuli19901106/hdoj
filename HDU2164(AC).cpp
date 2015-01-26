#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	char s1[100], s2[100];
	int w1, w2;
	int ti, t;
	int n, i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			w1 = 0;
			w2 = 0;
			for(i = 0; i < n; ++i){
				scanf("%s%s", s1, s2);
				if(s1[0] == 'R' && s2[0] == 'S'){
					++w1;
				}else if(s1[0] == 'S' && s2[0] == 'P'){
					++w1;
				}else if(s1[0] == 'P' && s2[0] == 'R'){
					++w1;
				}else if(s1[0] == 'R' && s2[0] == 'P'){
					++w2;
				}else if(s1[0] == 'P' && s2[0] == 'S'){
					++w2;
				}else if(s1[0] == 'S' && s2[0] == 'R'){
					++w2;
				}
			}

			if(w1 > w2){
				printf("Player 1\n");
			}else if(w1 < w2){
				printf("Player 2\n");
			}else{
				printf("TIE\n");
			}
		}
	}

	return 0;
}
