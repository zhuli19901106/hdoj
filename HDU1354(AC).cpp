#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

typedef struct st{
	char type;
	int x, y;
	bool happy;
	string text;
}st;

int n;
st a[101];
int c[101];
int cc;
int v[101];
bool success;

void dfs(int i, int idx)
{
	if(success){
		return;
	}
	c[idx] = i;
	if(a[i].type == 'C'){
		if(!v[a[i].x]){
			v[a[i].x] = 1;
			dfs(a[i].x, idx + 1);
			v[a[i].x] = 0;
		}
		if(!v[a[i].y]){
			v[a[i].y] = 1;
			dfs(a[i].y, idx + 1);
			v[a[i].y] = 0;
		}
	}else if(a[i].type == 'E'){
		if(a[i].happy){
			cc = idx + 1;
			success = true;
		}
	}
}

int main()
{
	int case_count, case_no;
	char s[1000];
	char buffer[1000];
	int i, j;
	int p, q;
	
	gets(s);
	sscanf(s, "%d", &case_count);
	for(case_no = 1; case_no <= case_count; ++case_no){
		gets(s);
		sscanf(s, "%d", &n);
		for(i = 1; i <= n; ++i){
			gets(s);
			a[i].type = s[0];
			p = 0;
			while(s[p] != '"'){
				++p;
			}
			++p;
			q = p;
			while(s[q] != '"'){
				++q;
			}
			for(j = p; j < q; ++j){
				buffer[j - p] = s[j];
			}
			buffer[j - p] = 0;
			a[i].text = string(buffer);
			if(a[i].type == 'C'){
				p = q + 1;
				while(s[p] == ' ' || s[p] == '\t'){
					++p;
				}
				sscanf(s + p, "%d%d", &a[i].x, &a[i].y);
			}else if(a[i].type == 'E'){
				p = q + 1;
				while(s[p] == ' ' || s[p] == '\t'){
					++p;
				}
				if(strcmp(s + p, "HAPPY") == 0){
					a[i].happy = true;
				}else{
					a[i].happy = false;
				}
			}
		}
		success = false;
		memset(v, 0, 101 * sizeof(int));
		memset(c, 0, 101 * sizeof(int));
		dfs(1, 0);
		printf("STORY %d\n", case_no);
		for(i = 0; i < cc; ++i){
			printf("%s\n", a[c[i]].text.data());
		}
	}
	
	return 0;
}
