#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int l, n;
map<string, string> mm;

int main()
{
	int i, j, len;
	string sa, sb;
	char s[1000];

	while(cin >> l >> n){
		mm.clear();
		for(i = 0; i < l; ++i){
			cin >> sa >> sb;
			mm[sa] = sb;
		}
		for(i = 0; i < n; ++i){
			cin >> sa;
			if(mm.find(sa) != mm.end()){
				cout << mm[sa] << endl;
			}else{
				for(j = 0; j < (int)sa.size(); ++j){
					s[j] = sa[j];
				}
				s[j] = 0;
				len = j;
				if(
					len >= 2 && s[len - 1] == 'y' && 
					!(
						s[len - 2] == 'a' || 
						s[len - 2] == 'e' || 
						s[len - 2] == 'i' || 
						s[len - 2] == 'o' || 
						s[len - 2] == 'u'
					)
				){
					s[len - 1] = 'i';
					s[len++] = 'e';
					s[len++] = 's';
					s[len] = 0;
				}else if(
					s[len - 1] == 'o' ||
					s[len - 1] == 's' ||
					s[len - 1] == 'x' ||
					(len >= 2 && s[len - 2] == 'c' && s[len - 1] == 'h') ||
					(len >= 2 && s[len - 2] == 's' && s[len - 1] == 'h')
				){
					s[len++] = 'e';
					s[len++] = 's';
					s[len] = 0;
				}else{
					s[len++] = 's';
					s[len] = 0;
				}
				sb = string(s);
				cout << sb << endl;
			}
		}
	}

	return 0;
}
