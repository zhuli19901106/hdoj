#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char map[15][15];
int loop[15][15];
int w, h;
int sx, sy, sc;
int sx2, sy2, sc2;
int loop_count, enter_count;
bool first_met, second_met;

bool inbound(const int &x, const int &y)
{
	return (x >= 1 && x <= w) && (y >= 1 && y <= h);
}

void go(int &x, int &y)
{
	switch(map[x][y]){
		case 'N':
			--x;
			break;
		case 'S':
			++x;
			break;
		case 'W':
			--y;
			break;
		case 'E':
			++y;
			break;
	}
}

int main()
{
	char buffer[1000];
	int i, j;

	while(true){
		if(scanf("%d%d%d", &w, &h, &sy) != 3){
			break;
		}else if(0 == w && 0 == h && 0 == sy){
			break;
		}
		sx2 = sx = 1;
		sy2 = sy;
		memset(map, 0, 15 * 15 * sizeof(char));
		memset(loop, 0, 15 * 15 * sizeof(int));
		for(i = 1; i <= w; ++i){
			scanf("%s", buffer);
			for(j = 1; j <= h; ++j){
				map[i][j] = buffer[j - 1];
			}
		}
		
		sc = sc2 = 0;
		first_met = second_met = false;
		while(true){
			if(sc > 0 && sc2 > 0 && sx == sx2 && sy == sy2){
				if(!first_met){
					first_met = true;
				}else if(!second_met){
					second_met = true;
					break;
				}
			}			
			
			if(inbound(sx, sy)){
				go(sx, sy);
				++sc;
			}else{
				break;
			}
			
			if(inbound(sx2, sy2)){
				if(!first_met){
					loop[sx2][sy2] = -1;
				}else if(first_met && !second_met){
					loop[sx2][sy2] = 1;
				}
				go(sx2, sy2);
				++sc2;
				if(inbound(sx2, sy2)){
					if(!first_met){
						loop[sx2][sy2] = -1;
					}else if(first_met && !second_met){
						loop[sx2][sy2] = 1;
					}
					go(sx2, sy2);
					++sc2;
				}else{
					break;
				}
			}else{
				break;
			}
		}
		
		loop_count = 0;
		enter_count = 0;
		for(i = 1; i <= w; ++i){
			for(j = 1; j <= h; ++j){
				if(loop[i][j] == -1){
					++enter_count;
				}else if(loop[i][j] == 1){
					++loop_count;
				}
			}
		}
		
		if(loop_count > 0){
			printf("%d step(s) before a loop of %d step(s)\n", enter_count, loop_count);
		}else{
			printf("%d step(s) to exit\n", enter_count);
		}
	}
	
	return 0;
}
