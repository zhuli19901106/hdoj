#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

char s[10000], t[10000];
map<string, int> mm;
int count;

int main()
{
	int i;

	while(gets(s) != NULL && strcmp(s, "#") != 0){
		mm.clear();
		count = 0;
		i = 0;
		while(true){
			while(s[i] == ' '){
				++i;
			}
			if(!s[i]){
				break;
			}
			if(sscanf(s + i, "%s", t) == 1){
				if(mm.find(string(t)) == mm.end()){
					mm[string(t)] = count;
					++count;
				}
			}
			while(s[i] != ' ' && s[i] != 0){
				++i;
			}
			if(!s[i]){
				break;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
