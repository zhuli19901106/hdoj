#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

int n;
queue<int> q;
stack<int> st;

int main()
{
	int t, ti;
	int tmp, i;
	char str[100];

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%s", &n, str);
			if(strcmp(str, "FIFO") == 0){
				while(!q.empty()){
					q.pop();
				}
				for(i = 0; i < n; ++i){
					scanf("%s", str);
					if(strcmp(str, "IN") == 0){
						scanf("%d", &tmp);
						q.push(tmp);
					}else if(strcmp(str, "OUT") == 0){
						if(q.empty()){
							printf("None\n");
						}else{
							printf("%d\n", q.front());
							q.pop();
						}
					}
				}
			}else if(strcmp(str, "FILO") == 0){
				while(!st.empty()){
					st.pop();
				}
				for(i = 0; i < n; ++i){
					scanf("%s", str);
					if(strcmp(str, "IN") == 0){
						scanf("%d", &tmp);
						st.push(tmp);
					}else if(strcmp(str, "OUT") == 0){
						if(st.empty()){
							printf("None\n");
						}else{
							printf("%d\n", st.top());
							st.pop();
						}
					}
				}
			}
		}
	}

	return 0;
}
