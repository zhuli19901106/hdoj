#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
using namespace std;

string next_inventory(const string &str)
{
	char s[1000];
	int i, a[10];
	
	memset(a, 0, 10 * sizeof(int));
	for(i = 0; i < (int)str.size(); ++i){
		++a[str[i] - '0'];
	}
	memset(s, 0, 1000 * sizeof(char));
	for(i = 0; i < 10; ++i){
		if(a[i]){
			sprintf(s + strlen(s), "%d%d", a[i], i);
		}
	}
	
	return string(s);
}

int main()
{
	map<string, int> mm;
	map<string, int>::iterator mit;
	char s[2000];
	int i, count, loop_len, loop_start;
	string s1;
	
	while(true){
		if(scanf("%s", s) != 1){
			break;
		}else if(strcmp(s, "-1") == 0){
			break;
		}
		mm.clear();
		count = 0;
		s1 = string(s);
		mm.insert(pair<string, int>(s1, count));
		++count;
		i = 0;
		while(i < 15){
			s1 = next_inventory(s1);
			mit = mm.find(s1);
			if(mit == mm.end()){
				mm.insert(pair<string, int>(s1, count));
				++count;
			}else{
				loop_len = count - mit->second;
				loop_start = mit->second;
				break;
			}
			++i;
		}
		if(i >= 15){
			printf("%s can not be classified after 15 iterations\n", s);
		}else if(loop_len > 1){
			printf("%s enters an inventory loop of length %d\n", s, loop_len);
		}else if(loop_start > 0){
			printf("%s is self-inventorying after %d steps\n", s, loop_start);
		}else{
			printf("%s is self-inventorying\n", s);
		}
	}
	
	return 0;
}
