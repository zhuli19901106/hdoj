#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

int m[1000][1000];

int main()
{
    int i, j;
    int n;
    int vstart;
    int vend;
    int len[1000];
    string idiom;
    string first[1000];
    string last[1000];
    queue<int> q;
    bool visited[1000];
    int sp[1000];
    int vout;
    const int INF = 1000000000;
    
    while(cin >> n && n){
        memset(m, 0, 1000 * 1000 * sizeof(int));
        for(i = 0; i < n; ++i){    
            cin >> len[i] >> idiom;
            first[i] = idiom.substr(0, 4);
            last[i] = idiom.substr(idiom.size() - 4, 4);
        }

        for(i = 0; i < n; ++i){
            for(j = 0; j < n; ++j){
                m[i][j] = INF;
            }
        }

        for(i = 0; i < n; ++i){
            for(j = 0; j < n; ++j){
                if(i == j){
                    continue;
                }else{
                    if(last[i] == first[j]){
                        m[i][j] = len[i];
                    }
                }
            }
        }

        for(i = 0; i < n; ++i){
            sp[i] = INF;
            visited[i] = false;
        }
        while(!q.empty()){
            q.pop();
        }
        vstart = 0;
        vend = n - 1;
        sp[vstart] = 0;
        q.push(vstart);
        while(!q.empty()){
            vout = q.front();
            q.pop();
            visited[vout] = true;
            for(i = 0; i < n; ++i){
                if(i == vout){
                    continue;
                }
                if(m[vout][i] < INF){
                    if(!visited[i]){
                        q.push(i);
                    }
                    if(sp[vout] + m[vout][i] < sp[i]){
                        sp[i] = sp[vout] + m[vout][i];
                    }
                }
            }
        }

        if(sp[vend] < INF){
            cout << sp[vend] << endl;
        }else{
            cout << -1 <<endl;
        }
    }

    return 0;
}

