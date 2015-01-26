#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string s;
	int win_goal;
	int lost_goal;
	int net_goal;
	int score;
}st;

bool comparator(const st &a, const st &b)
{
	if(a.score == b.score){
		if(a.net_goal == b.net_goal){
			if(a.win_goal == b.win_goal){
				return a.s < b.s;
			}else{
				return a.win_goal > b.win_goal;
			}
		}else{
			return a.net_goal > b.net_goal;
		}
	}else{
		return a.score > b.score;
	}
}

map<string, int> mm;

vector<st> vv;
int n, n2;

int main()
{
	int i;
	char str1[2000], str2[2000];
	string s1, s2;
	int x, y;
	int i1, i2;
	map<string, int>::iterator mit;

	while(scanf("%d", &n) == 1){
		mm.clear();
		vv.clear();
		n2 = n * (n - 1);
		for(i = 0; i < n2; ++i){
			scanf("%s%*s%s%d%*1s%d", str1, str2, &x, &y);
			s1 = string(str1);
			s2 = string(str2);
			mit = mm.find(s1);
			if(mit == mm.end()){
				mm[s1] = (int)vv.size();
				i1 =  vv.size();
				vv.push_back(st());
				vv[i1].lost_goal = 0;
				vv[i1].net_goal = 0;
				vv[i1].score = 0;
				vv[i1].s = string(s1);
				vv[i1].win_goal = 0;
			}else{
				i1 = mit->second;
			}

			mit = mm.find(s2);
			if(mit == mm.end()){
				mm[s2] = (int)vv.size();
				i2 =  vv.size();
				vv.push_back(st());
				vv[i2].lost_goal = 0;
				vv[i2].net_goal = 0;
				vv[i2].score = 0;
				vv[i2].s = string(s2);
				vv[i2].win_goal = 0;
			}else{
				i2 = mit->second;
			}

			vv[i1].win_goal += x;
			vv[i1].lost_goal += y;
			vv[i1].net_goal += (x -  y);

			vv[i2].win_goal += y;
			vv[i2].lost_goal += x;
			vv[i2].net_goal += (y -  x);

			if(x > y){
				vv[i1].score += 3;
			}else if(x < y){
				vv[i2].score += 3;
			}else{
				vv[i1].score += 1;
				vv[i2].score += 1;
			}
		}
		sort(vv.begin(), vv.end(), comparator);
		for(i = 0; i < (int)vv.size(); ++i){
			printf("%s %d\n", vv[i].s.data(), vv[i].score);
		}
		printf("\n");
	}

	return 0;
}
