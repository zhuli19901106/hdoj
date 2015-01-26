#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int n;
int a[50][50];
long long int f[50][50];

int main()
{
	int i, j;
	string s;

	while(cin >> n && n != -1){
		memset(a, 0, 50 * 50 * sizeof(int));

		for(i = 0; i < n; ++i){
			cin >> s;
			for(j = 0; j < n; ++j){
				a[i][j] = s[j] - '0';
			}
		}

		memset(f, 0, 50 * 50 * sizeof(long long int));
		f[0][0] = 1;
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				if(a[i][j] == 0){
					continue;
				}
				f[i + a[i][j]][j] += f[i][j];
				f[i][j + a[i][j]] += f[i][j];
			}
		}

		cout << f[n - 1][n - 1] << endl;
	}

	return 0;
}
