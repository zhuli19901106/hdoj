#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct team{
    string name;
    int sub[4];
    int actime[4];
    bool ac[4];
    int acc;
    int penalty;
}Team;
vector<Team> vv;
int n;

bool comparator(const Team &a, const Team &b)
{
    if(a.acc == b.acc){
        return a.penalty < b.penalty;
    }else{
        return a.acc > b.acc;
    }
}

int main()
{
    int i, j;
    Team t;

    while(cin >> n){
        vv.clear();
        for(i = 0; i < n; ++i){
            cin >> t.name;
            t.acc = 0;
            t.penalty = 0;
            for(j = 0; j < 4; ++j){
                cin >> t.sub[j] >> t.actime[j];
                if(!t.actime[j]){
                    t.ac[j] = false;
                }else{
                    t.ac[j] = true;
                    ++t.acc;
                    t.penalty += t.actime[j] + 20 * (t.sub[j] - 1);
                }
            }
            vv.push_back(t);
        }
        sort(vv.begin(), vv.end(), comparator);
        cout << vv[0].name << " " << vv[0].acc << " " << vv[0].penalty << endl;
    }

    return 0;
}

