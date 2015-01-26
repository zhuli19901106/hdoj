#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct item{
	string name;
	int param;
	int priority;
	int serial;
};

struct comp{
	bool operator()(const struct item &a, const struct item &b)
	{
		if(a.priority == b.priority){
			return a.serial > b.serial;
		}else{
			return a.priority > b.priority;
		}
	}
};

int main()
{
	priority_queue<item, vector<item>, comp> pq;
	struct item it;
	char str[1000];
	char msgname[1000];
	int param;
	int priority;
	int serial;
	
	while(!pq.empty()){
		pq.pop();
	}
	
	serial = 0;
	while(true){
		if(gets(str) == NULL){
			break;
		}
		
		if(strcmp(str, "GET") == 0){
			if(!pq.empty()){
				it = pq.top();
				pq.pop();
				printf("%s %d\n", it.name.data(), it.param);
			}else{
				printf("EMPTY QUEUE!\n");
			}
		}else{
			sscanf(str, "PUT%s%d%d", msgname, &param, &priority);
			it.name = string(msgname);
			it.param = param;
			it.priority = priority;
			it.serial = serial;
			++serial;
			pq.push(it);
		}
	}
	
	return 0;
}
