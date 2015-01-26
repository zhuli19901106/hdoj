#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int w[21][21][21];
int main()
{
	int a, b, c;
	int miss_count;
	const int UNDEFINED = -1;
	
	for(a = 0; a < 21; ++a){
		for(b = 0; b < 21; ++b){
			for(c = 0; c < 21; ++c){
				w[a][b][c] = UNDEFINED;
			}
		}
	}

	for(a = 0; a < 21; ++a){
		for(b = 0; b < 21; ++b){
			w[a][b][0] = 1;
			w[a][0][b] = 1;
			w[0][a][b] = 1;
		}
	}
	
	for(a = 1; a < 21; ++a){
		for(b = 1; b < 21; ++b){
			for(c = 1; c < 21; ++c){
				if(a < b && b < c){
					w[a][b][c] = w[a][b][c -1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
				}else{
					w[a][b][c] = w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];
				}
			}
		}
	}

	miss_count = 0;
	for(a = 0; a < 21; ++a){
		for(b = 0; b < 21; ++b){
			for(c = 0; c < 21; ++c){
				if(w[a][b][c] == UNDEFINED){
					++miss_count;
				}
			}
		}
	}
	if(miss_count > 0){
		printf("ERROR: %d result(s) missing.\n", miss_count);
	}

	while(true){
		if(scanf("%d%d%d", &a, &b, &c) != 3){
			break;
		}else if(a == -1 && b == -1 && c == -1){
			break;
		}
		printf("w(%d, %d, %d) = ", a, b, c);
		if(a <= 0 || b <= 0 || c <= 0){
			printf("1\n");
		}else if(a > 20 || b > 20 || c > 20){
			printf("%d\n", w[20][20][20]);
		}else{
			printf("%d\n", w[a][b][c]);
		}
	}
	
	return 0;
}
