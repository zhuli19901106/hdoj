#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int t, n;

int main()
{
    int i;
    int ti;
    string str;
    
    while(cin >> t){
        for(ti = 0; ti < t; ++ti){
            cin >> n;
            v.clear();
            for(i = 0; i < n; ++i){
                cin >> str;
                v.push_back(str);
            }
            sort(v.begin(), v.end());
            for(i = 0; i < n - 1; ++i){
                if(
                    (v[i + 1].size() >= v[i].size())
                    &&
                    (v[i + 1].substr(0, v[i].size()) == v[i])
                ){
                    break;
                }
            }
            if(i == n - 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}

