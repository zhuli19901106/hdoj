#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<string> word_list;
vector<string> terms;

int main()
{
	int i, j, k, q, len;
	char s[1000];
	char buffer[1000];
	bool terminate;
	char pos[30];
	int cpos[30];
	char neg[30];
	int cneg[30];
	char uns[30];
	int cuns[30];
	int pc, nc, uc;
	vector<string>::iterator it;
	bool match;
	int c1, c2, c3;
	
	terminate = false;
	while(!terminate){
		word_list.clear();
		while(true){
			if(scanf("%s", s) != 1){
				terminate = true;
				break;
			}else if(strcmp(s, "#") == 0){
				terminate = true;
				break;
			}else if(strcmp(s, "*") == 0){
				break;
			}else{
				word_list.push_back(string(s));
			}
		}
		if(terminate){
			break;
		}
		if(word_list.size() > 0){
			sort(word_list.begin(), word_list.end());
		}
		
		while(true){
			terms.clear();
			scanf("%s", s);
			if(strcmp(s, "**") == 0){
				printf("$\n");
				break;
			}
			len = strlen(s);
			i = 0;
			j = 0;
			while(true){
				if(s[i] == '|'){
					buffer[j] = 0;
					terms.push_back(string(buffer));
					j = 0;
					++i;
				}else if(s[i] == 0){
					buffer[j] = 0;
					terms.push_back(string(buffer));
					break;
				}else{
					buffer[j] = s[i];
					++i;
					++j;
				}
			}
			
			match = false;
			for(i = 0; !match && i < (int)word_list.size(); ++i){
				for(j = 0; !match && j < (int)terms.size(); ++j){
					k = 0;
					pc = 0;
					nc = 0;
					uc = 0;
					while(true){
						if(k >= (int)terms[j].size()){
							break;
						}else if(terms[j][k] >= 'a' && terms[j][k] <= 'z'){
							uns[uc++] = terms[j][k];
							++k;
						}else if(terms[j][k] == '-'){
							neg[nc++] = terms[j][k + 1];
							k += 2;
						}else if(terms[j][k] == '+'){
							pos[pc++] = terms[j][k + 1];
							k += 2;
						}
					}
					memset(cpos, 0, 30 * sizeof(int));
					memset(cneg, 0, 30 * sizeof(int));
					memset(cuns, 0, 30 * sizeof(int));
					for(k = 0; k < (int)word_list[i].size(); ++k){
						for(q = 0; q < pc; ++q){
							if(word_list[i][k] == pos[q]){
								cpos[q] = 1;
							}
						}
						for(q = 0; q < nc; ++q){
							if(word_list[i][k] == neg[q]){
								cneg[q] = 1;
							}
						}
						for(q = 0; q < uc; ++q){
							if(word_list[i][k] == uns[q]){
								cuns[q] = 1;
							}
						}
					}
					c1 = 1;
					for(k = 0; k < pc; ++k){
						c1 = c1 && cpos[k];
					}
					c2 = 0;
					for(k = 0; k < nc; ++k){
						c2 = c2 || cneg[k];
					}
					c3 = 0;
					for(k = 0; k < uc; ++k){
						c3 = c3 || cuns[k];
					}
					if(uc == 0){
						c3 = 1;
					}

					if(c1 && !c2 && c3){
						printf("%s\n", word_list[i].data());
						match = true;
					}

					if(match){
						break;
					}
				}
			}
			
			if(!match){
				printf("NONE\n");
			}
		}
	}
	
	return 0;
}
