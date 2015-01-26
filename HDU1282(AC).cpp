#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

__int64 get_reverse(__int64 n)
{
	__int64 res;

	res = 0;
	while(n > 0){
		res *= 10;
		res += n % 10;
		n /= 10;
	}

	return res;
}

bool palindrome(__int64 n)
{
	char s[20];
	int i, len;

	sprintf(s, "%I64d", n);
	len = strlen(s);
	
	i = 0;
	while(i < len - 1 - i){
		if(s[i] != s[len - 1 - i]){
			return false;
		}else{
			++i;
		}
	}

	return true;
}

int main()
{
	int i;
	__int64 n;
	vector<__int64> v;

	while(scanf("%I64d", &n) == 1){
		v.clear();
		while(!palindrome(n)){
			v.push_back(n);
			n = n + get_reverse(n);
		}
		v.push_back(n);

		printf("%d\n", (int)v.size() - 1);
		printf("%I64d", v[0]);
		for(i = 1; i < (int)v.size(); ++i){
			printf("--->%I64d", v[i]);
		}
		printf("\n");
	}

	return 0;
}
