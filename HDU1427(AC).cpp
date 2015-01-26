#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct op{
	int x;
	int y;
	char c;
}op;
int a[4];
int ac;
op o[4];
int oc;
bool suc;

int val(const char s[])
{
	if(strcmp(s, "A") == 0){
		return 1;
	}else if(strcmp(s, "2") == 0){
		return 2;
	}else if(strcmp(s, "3") == 0){
		return 3;
	}else if(strcmp(s, "4") == 0){
		return 4;
	}else if(strcmp(s, "5") == 0){
		return 5;
	}else if(strcmp(s, "6") == 0){
		return 6;
	}else if(strcmp(s, "7") == 0){
		return 7;
	}else if(strcmp(s, "8") == 0){
		return 8;
	}else if(strcmp(s, "9") == 0){
		return 9;
	}else if(strcmp(s, "10") == 0){
		return 10;
	}else if(strcmp(s, "J") == 0){
		return 11;
	}else if(strcmp(s, "Q") == 0){
		return 12;
	}else if(strcmp(s, "K") == 0){
		return 13;
	}else{
		return -1;
	}
}

void dfs()
{
	int i, j, k;
	int x, y;
	int b[4];
	int bc;

	if(suc){
		return;
	}

	if(ac == 1){
		if(a[0] == 24){
			suc = true;
			/*
			for(i = 0; i < oc; ++i){
				int res;
				if(o[i].c == '+'){
					res = o[i].x + o[i].y;
				}else if(o[i].c == '-'){
					res = o[i].x - o[i].y;
				}else if(o[i].c == '*'){
					res = o[i].x * o[i].y;
				}else if(o[i].c == '/'){
					res = o[i].x / o[i].y;
				}
				printf("%d %c %d = %d\n", o[i].x, o[i].c, o[i].y, res);
			}
			*/
		}
		return;
	}
	/*
	for(i = 0; i < ac; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	*/
	for(i = 0; i < ac; ++i){
		for(j = i + 1; j < ac; ++j){
			for(k = 0; k < 4; ++k){
				b[k] = a[k];
			}
			bc = ac;
			ac = 0;
			x = a[i];
			y = a[j];

			for(k = 0; k < bc; ++k){
				if(k == i || k == j){
					continue;
				}else{
					a[ac++] = b[k];
				}
			}
			a[ac++] = x * y;
			o[oc].x = x;
			o[oc].y = y;
			o[oc].c = '*';
			++oc;
			dfs();
			--oc;
			for(k = 0; k < bc; ++k){
				a[k] = b[k];
			}
			ac = bc;

			for(k = 0; k < 4; ++k){
				b[k] = a[k];
			}
			bc = ac;
			ac = 0;
			x = a[i];
			y = a[j];
			for(k = 0; k < bc; ++k){
				if(k == i || k == j){
					continue;
				}else{
					a[ac++] = b[k];
				}
			}
			if(x >= y && y && x % y == 0){
				a[ac++] = x / y;
				o[oc].x = x;
				o[oc].y = y;
				o[oc].c = '/';
				++oc;
				dfs();
				--oc;
			}else if(x && y % x == 0){
				a[ac++] = y / x;
				o[oc].x = y;
				o[oc].y = x;
				o[oc].c = '/';
				++oc;
				dfs();
				--oc;
			}
			for(k = 0; k < 4; ++k){
				a[k] = b[k];
			}
			ac = bc;

			for(k = 0; k < 4; ++k){
				b[k] = a[k];
			}
			bc = ac;
			ac = 0;
			x = a[i];
			y = a[j];
			for(k = 0; k < bc; ++k){
				if(k == i || k == j){
					continue;
				}else{
					a[ac++] = b[k];
				}
			}
			a[ac++] = x + y;
			o[oc].x = x;
			o[oc].y = y;
			o[oc].c = '+';
			++oc;
			dfs();
			--oc;
			for(k = 0; k < 4; ++k){
				a[k] = b[k];
			}
			ac = bc;

			for(k = 0; k < 4; ++k){
				b[k] = a[k];
			}
			bc = ac;
			ac = 0;
			x = a[i];
			y = a[j];
			for(k = 0; k < bc; ++k){
				if(k == i || k == j){
					continue;
				}else{
					a[ac++] = b[k];
				}
			}
			if(x >= y){
				a[ac++] = x - y;
				o[oc].x = x;
				o[oc].y = y;
				o[oc].c = '-';
				++oc;
				dfs();
				--oc;
			}else{
				a[ac++] = y - x;
				o[oc].x = y;
				o[oc].y = x;
				o[oc].c = '-';
				++oc;
				dfs();
				--oc;
			}
			for(k = 0; k < 4; ++k){
				a[k] = b[k];
			}
			ac = bc;
		}
	}
}

int main()
{
	char s[1000];

	while(true){
		if(scanf("%s", s) != 1){
			break;
		}
		a[0] = val(s);
		scanf("%s", s);
		a[1] = val(s);
		scanf("%s", s);
		a[2] = val(s);
		scanf("%s", s);
		a[3] = val(s);
		if(
			a[0] < 1 || a[0] > 13 ||
			a[1] < 1 || a[1] > 13 ||
			a[2] < 1 || a[2] > 13 ||
			a[3] < 1 || a[3] > 13
		){
			printf("Invalid input.\n");
			continue;
		}
		suc = false;
		ac = 4;
		oc = 0;
		dfs();

		if(suc){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}
