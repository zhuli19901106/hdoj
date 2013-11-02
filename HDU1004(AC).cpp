#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
    string s;
    int c;
}st;

int main()
{
    map<string, int> mm;
    map<string, int>::iterator mit;
    vector<st> v;
    st m_st;
    int i;
    int n;
    string str;
    string popular_str;
    int pc;
    
    while(cin >> n && n){
        mm.clear();
        v.clear();
        popular_str = "";
        pc = 0;
        for(i = 0; i < n; ++i){
            cin >> str;
            mit = mm.find(str);
            if(mit == mm.end()){
                mm.insert(pair<string, int>(str, 1));
                if(popular_str == "" || pc < 1){
                    popular_str = str;
                    pc = 1;
                }
            }else{
                ++(mit->second);
                if(popular_str == "" || pc < mit->second){
                    popular_str = str;
                    pc = mit->second;
                }
            }
        }
        cout << popular_str << endl;
    }

    return 0;
}

