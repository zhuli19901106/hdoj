#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int mem[32];
int acc;
int pc;
bool terminate;

int main()
{
	int i, j;
	char s[100];
	int b;

	while(true){
		for(i = 0; i < 32; ++i){
			if(scanf("%s", s) != 1){
				break;
			}
			b = 0;
			for(j = 0; j < 8; ++j){
				b <<= 1;
				b += (s[j] - '0');
			}
			mem[i] = b;
		}
		if(i < 32){
			break;
		}

		pc = 0;
		acc = 0;
		terminate = false;
		while(!terminate){
			switch((b = mem[pc], pc = (pc + 1) % 32, b >> 5)){
			case 0:
				mem[b & 0x1F] = acc;
				break;
			case 1:
				acc = mem[b & 0x1F];
				break;
			case 2:
				if(!acc){
					pc = b & 0x1F;
				}
				break;
			case 3:
				break;
			case 4:
				acc = (acc + 0xFF) % 0x100;
				break;
			case 5:
				acc = (acc + 0x01) % 0x100;
				break;
			case 6:
				pc = b & 0x1F;
				break;
			case 7:
				terminate = true;
				break;
			}
		}

		for(i = 0; i < 8; ++i){
			printf("%d", !!(acc & (1 << (7 - i))));
		}
		printf("\n");
	}

	return 0;
}
