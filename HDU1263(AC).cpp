#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int t, ti;
	int n;
	int i;
	map<string, map<string, int> > mm;
	string ff, pp;
	int num;

	while(cin >> t){
		for(ti = 0; ti < t; ++ti){
			if(ti > 0){
				cout << endl;
			}

			mm.clear();

			cin >> n;
			for (i = 0; i != n; ++i){
				cin >> ff >> pp >> num;
				mm[pp][ff] += num;
			}
			for(map<string, map<string, int> >::iterator mit1 = mm.begin(); mit1 != mm.end(); ++mit1){
				cout << mit1->first << endl;
				for(map<string, int>::iterator mit2 = mit1->second.begin(); mit2 != mit1->second.end(); ++mit2){
					cout << "   |----" << mit2->first << "(" << mit2->second << ")" << endl;
				}
			}
		}
    }

    return 0;
}
