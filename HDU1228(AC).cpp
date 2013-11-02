#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int a, b;
map<string, int> mm;

int main()
{
    string str;

    mm.clear();
    mm["zero"] = 0;
    mm["one"] = 1;
    mm["two"] = 2;
    mm["three"] = 3;
    mm["four"] = 4;
    mm["five"] = 5;
    mm["six"] = 6;
    mm["seven"] = 7;
    mm["eight"] = 8;
    mm["nine"] = 9;

    while(cin >> str){
        a = b = 0;
        a = mm[str];
        while(cin >> str && str != "+"){
            a = a * 10 + mm[str];
        }
        while(cin >> str && str != "="){
            b = b * 10 + mm[str];
        }
        if(a || b){
            cout << a + b << endl;
        }else{
            break;
        }
    }

    return 0;
}

