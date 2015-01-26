#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> v;
bool suc;
int max_len;

void reverse_string(char s[])
{
	int i, len;
	char ch;

	if(!s){
		return;
	}
	len = strlen(s);
	i = 0;
	while(i < len - 1 - i){
		ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
		++i;
	}
}

bool check_common_substr(const string &sub)
{
	int i;
	char s[500];

	for(i = 1; i < (int)v.size(); ++i){
		if(v[i].find(sub) == string::npos){
			strcpy(s, sub.data());
			reverse_string(s);
			if(v[i].find(string(s)) == string::npos){
				return false;
			}
		}
	}

	return true;
}

bool comparator(const string &a, const string &b)
{
	if(a.size() == b.size()){
		return a < b;
	}else{
		return a.size() < b.size();
	}
}

int main()
{
	int i, j;
	int t, ti;
	char s[500];
	string sub, str;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			v.clear();
			for(i = 0; i < n; ++i){
				scanf("%s", s);
				v.push_back(string(s));
			}
			sort(v.begin(), v.end(), comparator);
			if(n == 1){
				printf("%d\n", v[0].size());
				continue;
			}
			suc = false;

			strcpy(s, v[0].data());
			str = string(s);
			for(i = str.size(); !suc && i > 0; --i){
				for(j = 0; !suc && j + i <= (int)str.size(); ++j){
					sub = str.substr(j, i);
					suc = check_common_substr(sub);
					if(suc){
						max_len = (int)sub.size();
					}
				}
			}

			if(suc){
				printf("%d\n", max_len);
			}else{
				printf("0\n");
			}
		}
	}

	return 0;
}
