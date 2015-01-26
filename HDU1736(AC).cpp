#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 5000;
char s[MAXN];
int len;

int main()
{
	char q1[] = "¡°";
	char q2[] = "¡±";
	int clen = strlen(q1);
	int qf;
	int i, j;

	memset(s, 0, MAXN * sizeof(char));
	while(gets(s) != NULL){
		len = strlen(s);
		for(i = 0; i < len; ++i){
			if(s[i] == ','){
				printf("£¬");
			}else if(s[i] == '.'){
				printf("¡£");
			}else if(s[i] == '!'){
				printf("£¡");
			}else if(s[i] == '?'){
				printf("£¿");
			}else if(s[i] == '"'){
				if(qf){
					printf("¡°");
				}else{
					printf("¡±");
				}
				qf = !qf;
			}else if(s[i] == '<' && s[i + 1] == '<'){
				printf("¡¶");
				++i;
			}else if(s[i] == '>' && s[i + 1] == '>'){
				printf("¡·");
				++i;
			}else{
				for(j = 0; j < clen; ++j){
					if(s[i + j] != q1[j]){
						break;
					}
				}
				if(j == clen){
					i += clen - 1;
					printf("%s", q1);
					qf = !qf;
				}else{
					for(j = 0; j < clen; ++j){
						if(s[i + j] != q2[j]){
							break;
						}
					}
					if(j == clen){
						i += clen - 1;
						printf("%s", q2);
						qf = !qf;
					}else{
						printf("%c", s[i]);
					}
				}
			}
		}
		printf("\n");
		memset(s, 0, MAXN * sizeof(char));
	}

	return 0;
}
