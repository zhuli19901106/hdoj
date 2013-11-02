#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int f[10000];
    int visited[10000];
    int start, end;
    int t, ti;
    queue<int> q;
    int i;
    bool suc;
    int count;
    int nout, nin;
    char str[10], ch;
    
    while(true){
        if(scanf("%d", &t) != 1){
            break;
        }
        for(ti = 0; ti < t; ++ti){
            while(!q.empty()){
                q.pop();
            }
            scanf("%d", &start);
            scanf("%d", &end);
            for(i = 0; i < 10000; ++i){
                f[i] = -1;
                visited[i] = 0;
            }
            count = 0;
            f[start] = 0;
            if(start == end){
                suc = true;
                printf("0\n");
                continue;
            }
            visited[start] = 1;
            q.push(start);

            suc = false;
            while(!q.empty()){
                nout = q.front();
                q.pop();
                sprintf(str, "%d", nout);
                for(i = 0; i < 4; ++i){
                    if(str[i] == '9'){
                        str[i] = '1';
                    }else{
                        ++str[i];
                    }
                    sscanf(str, "%d", &nin);
                    if(!visited[nin]){
                        f[nin] = f[nout] + 1;
                        if(nin == end){
                            suc = true;
                            break;
                        }
                        visited[nin] = 1;
                        q.push(nin);
                    }
                    if(str[i] == '1'){
                        str[i] = '9';
                    }else{
                        --str[i];
                    }

                    if(str[i] == '1'){
                        str[i] = '9';
                    }else{
                        --str[i];
                    }
                    sscanf(str, "%d", &nin);
                    if(!visited[nin]){
                        f[nin] = f[nout] + 1;
                        if(nin == end){
                            suc = true;
                            break;
                        }
                        visited[nin] = 1;
                        q.push(nin);
                    }
                    if(str[i] == '9'){
                        str[i] = '1';
                    }else{
                        ++str[i];
                    }
                }
                if(suc){
                    break;
                }
                for(i = 0; i < 3; ++i){
                    ch = str[i];
                    str[i] = str[i + 1];
                    str[i + 1] = ch;
                    sscanf(str, "%d", &nin);
                    if(!visited[nin]){
                        f[nin] = f[nout] + 1;
                        visited[nin] = 1;
                        q.push(nin);
                    }
                    ch = str[i];
                    str[i] = str[i + 1];
                    str[i + 1] = ch;
                }
                if(suc){
                    break;
                }
            }
            printf("%d\n", f[end]);
        }
    }
    
    return 0;
}

