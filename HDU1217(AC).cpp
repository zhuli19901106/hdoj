#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const double INF = 99999999;
int n, m;
map<string, int> mm;

double rate;
string s, s1, s2;
double f[50][50];


void floyd()
{
	int i, j, k;

	for(k = 1; k <= n; ++k){
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= n; ++j){
				if(f[i][j] < f[i][k] * f[k][j]){
					f[i][j] = f[i][k] * f[k][j];
				}
			}
		}
	}
}

int main()
{
	int ti;
	int i;
	bool suc;

	ti = 0;
	while(cin >> n && n)
	{
		++ti;
		memset(f, 0, 50 * 50 * sizeof(double));
		mm.clear();

		for(i = 1; i <= n; ++i){
			cin >> s;
			mm[s] = i;
			f[i][i]=1;
		}

		cin >> m;
		for(i = 1; i <= m; ++i){
			cin >> s1 >> rate >> s2;
			f[mm[s1]][mm[s2]] = rate;
		}

		floyd();

		suc = false;
		for(i = 1; i <= n; ++i){
			if(f[i][i] > 1.0){
				suc = true;
				break;
			}
		}
	 	if(suc){
			cout<<"Case "<< ti <<": Yes"<<endl;
		}else{
			cout<<"Case "<< ti <<": No"<<endl;
		}
	}

	return 0;
}
