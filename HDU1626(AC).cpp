#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int binary_reverse(int n)
{
	int i;
	int res;

	res = 0;
	for(i = 0; i < 7; ++i){
		res |= ((n & (1 << i)) >> i << (7 - i));
	}

	return res;
}

int main()
{
	char s[1100];
	int CRC, i;
	const int g = 34943;

	while(gets(s) != NULL && strcmp(s, "#")){
		CRC = 0;
		for(i = 0; s[i]; ++i){
			CRC = (CRC * 256 + s[i]) % g;
		}
		CRC = CRC * 256 % g;
		CRC = CRC * 256 % g;
		CRC = (g - CRC) % g;
		printf("%02X %02X\n", (CRC & 0xff00) >> 8, CRC & 0xff);
	}

	return 0;
}
