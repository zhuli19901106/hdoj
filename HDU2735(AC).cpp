#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

//Suppose all given a and b are greater than 0
int gcd(int a, int b)
{
    if(a == b){
        return a;
    }else{
        while(true){
            if(a > b){
                if(a % b == 0){
                    return b;
                }else{
                    a = a % b;
                }
            }else{
                if(b % a == 0){
                    return a;
                }else{
                    b = b % a;
                }
            }
        }
    }
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

class Frac
{
public:
    int x;
    int y;
    Frac(int _x = 0, int _y = 1);
    friend const Frac operator + (const Frac &, const Frac &);
    friend const Frac operator * (const Frac &, const Frac &);
};

Frac::Frac(int _x, int _y)
{
    x = _x;
    y = _y;
    if(x > 0 && y > 0){
        _x = gcd(x, y);
        x /= _x;
        y /= _x;
    }
}

const Frac operator + (const Frac &a, const Frac &b)
{
    int tx, ty, tgcd;
    
    if(a.x == 0){
        return b;
    }else if(b.x == 0){
        return a;
    }
    
    ty = lcm(a.y, b.y);
    tx = a.x * (ty / a.y) + b.x * (ty / b.y);
    tgcd = gcd(tx, ty);
    tx /= tgcd;
    ty /= tgcd;
    
    return Frac(tx, ty);
}

const Frac operator * (const Frac &a, const Frac &b)
{
    int tx, ty, tgcd;
    
    if(a.x == 0 || b.x == 0){
        return Frac(0, 1);
    }
    
    tx = a.x * b.x;
    ty = a.y * b.y;
    tgcd = gcd(tx, ty);
    tx /= tgcd;
    ty /= tgcd;
    
    return Frac(tx, ty);
}

int main()
{
    char s[1000];
    int len;
    Frac res;
    Frac f;
    int pos;
    int i;
    int speed;
    bool over;

    while(true){
        if(gets(s) == NULL){
            break;
        }else if(strcmp(s, "#") == 0){
            break;
        }
        len = strlen(s);
        res = Frac(0, 1);
        for(i = 0; i < len; ++i){
            switch(s[i]){
            case '/':
                pos = i - 1;
                speed = -1;
                over = false;
                while(!over){
                    if(pos <= -1 || pos >= len){
                        over = true;
                        break;
                    }else if(s[pos] == '.'){
                        over = true;
                        break;
                    }else if(s[pos] == '_'){
                        --pos;
                    }else if(s[pos] == '|'){
                        res = res + Frac(1, len);
                        over = true;
                        break;
                    }else if(s[pos] == '\\'){
                        res = res + Frac(1, len);
                        over = true;
                        break;
                    }
                }
                break;
            case '\\':
                pos = i + 1;
                speed = +1;
                over = false;
                while(!over){
                    if(pos <= -1 || pos >= len){
                        over = true;
                        break;
                    }else if(s[pos] == '.'){
                        over = true;
                        break;
                    }else if(s[pos] == '_'){
                        ++pos;
                    }else if(s[pos] == '|'){
                        res = res + Frac(1, len);
                        over = true;
                        break;
                    }else if(s[pos] == '/'){
                        res = res + Frac(1, len);
                        over = true;
                        break;
                    }
                }
                break;
            case '|':
                pos = i - 1;
                speed = -1;
                over = false;
                while(!over){
                    if(pos <= -1 || pos >= len){
                        over = true;
                        break;
                    }else if(s[pos] == '.'){
                        over = true;
                        break;
                    }else if(s[pos] == '_'){
                        --pos;
                    }else if(s[pos] == '|'){
                        res = res + Frac(1, 2 * len);
                        over = true;
                        break;
                    }else if(s[pos] == '\\'){
                        res = res + Frac(1, 2 * len);
                        over = true;
                        break;
                    }
                }

                pos = i + 1;
                speed = +1;
                over = false;
                while(!over){
                    if(pos <= -1 || pos >= len){
                        over = true;
                        break;
                    }else if(s[pos] == '.'){
                        over = true;
                        break;
                    }else if(s[pos] == '_'){
                        ++pos;
                    }else if(s[pos] == '|'){
                        res = res + Frac(1, 2 * len);
                        over = true;
                        break;
                    }else if(s[pos] == '/'){
                        res = res + Frac(1, 2 * len);
                        over = true;
                        break;
                    }
                }
                break;
            case '_':
                res = res + Frac(1, len);
                break;
            case '.':
                break;
            }
        }

        res.x = res.y - res.x;
        //printf("%d/%d\n", res.x, res.y);
        printf("%d\n", (int)(res.x * 100.0 / res.y));
    }
    
    return 0;
}

