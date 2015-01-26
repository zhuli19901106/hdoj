#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int a[1000000];
queue<int> q[1000];
queue<int> qt;
int n, t;

int main()
{
	int i, j, k;
	int ti, tmp;
	char s[1000];

	ti = 0;
	while(scanf("%d", &t) == 1 && t){
		++ti;
		memset(a, 0, 1000000 * sizeof(int));
		for(i = 0; i < t; ++i){
			scanf("%d", &k);
			for(j = 0; j < k; ++j){
				scanf("%d", &tmp);
				a[tmp] = i;
			}
		}

		printf("Scenario #%d\n", ti);
		while(true){
			scanf("%s", s);
			if(strcmp(s, "ENQUEUE") == 0){
				scanf("%d", &tmp);
				if(q[a[tmp]].empty()){
					qt.push(a[tmp]);
					q[a[tmp]].push(tmp);
				}else{
					q[a[tmp]].push(tmp);
				}
			}else if(strcmp(s, "DEQUEUE") == 0){
				if(!qt.empty()){
					printf("%d\n", q[qt.front()].front());
					q[qt.front()].pop();
					if(q[qt.front()].empty()){
						qt.pop();
					}
				}
			}else if(strcmp(s, "STOP") == 0){
				break;
			}
		}
		printf("\n");

		//clear up data
		for(i = 0; i < t; ++i){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
		while(!qt.empty()){
			qt.pop();
		}
	}

	return 0;
}
