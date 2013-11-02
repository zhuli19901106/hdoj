#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef unsigned char byte;
int cube[201];
byte hash[8000001];

int main()
{
    int a, b, c, d;
    int i;
    
    memset(hash, 0, 8000001 * sizeof(byte));
    for(i = 0; i <= 200; ++i){
        cube[i] = i * i * i;
        hash[cube[i]] = i;
    }
    
    for(a = 3; a <= 200; ++a){
        for(b = 2; b < a; ++b){
            if(3 * cube[b] > cube[a]){
                break;
            }
            for(c = b; c < a; ++c){
                if(cube[b] + 2 * cube[c] > cube[a]){
                    break;
                }
                d = hash[cube[a] - cube[b] - cube[c]];
                if(d){
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    
    return 0;
}

