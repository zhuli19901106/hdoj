#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int digits[10][7] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int main()
{
	char array[23][104];
	char str[100];
	int s, n;
	int i, j, k;
	int total_col, total_row;
	int count_digit;
	
	while(true){
		scanf("%d%d", &s, &n);
		if(0 == s && 0 == n){
			break;
		}
		
		sprintf(str, "%d", n);
		count_digit = strlen(str);
		
		total_row = 2 * s + 3;
		total_col = count_digit * (s + 3) - 1;
		for(i = 0; i < total_row; ++i){
			for(j = 0; j < total_col; ++j){
				array[i][j] = ' ';
			}
		}
		for(i = 0; i < total_row; ++i){
			array[i][total_col] = '\0';
		}
		
		for(i = 0; i < count_digit; ++i){
			for(j = 0; j < 7; ++j){
				if(digits[str[i] - '0'][j]){
					for(k = 0; k < s; ++k){
						switch(j){
							case 0:
								array[0][i * (s + 3) + k + 1] = '-';
								break;
							case 1:
								array[k + 1][i * (s + 3) + s + 1] = '|';
								break;
							case 2:
								array[k + s + 2][i * (s + 3) + s + 1] = '|';
								break;
							case 3:
								array[2 * s + 2][i * (s + 3) + k + 1] = '-';
								break;
							case 4:
								array[k + s + 2][i * (s + 3)] = '|';
								break;
							case 5:
								array[k + 1][i * (s + 3)] = '|';
								break;
							case 6:
								array[s + 1][i * (s + 3) + k + 1] = '-';
								break;
						}
					}
				}
			}
		}
		
		for(i = 0; i < total_row; ++i){
			printf("%s\n", array[i]);
		}
		printf("\n");
	}
	
	return 0;
}
