#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char UpperDict[27];
    char LowerDict[27];
    char Message[1000];
    char Decrypt[1000];
    int i;

    while(true){
        if(gets(LowerDict) == NULL){
            break;
        }
        for(i = 0; i < 26; i++)
        {
            UpperDict[i] = LowerDict[i] - 'a' + 'A';
        }
        UpperDict[26] = 0;

        gets(Message);
        for(i = 0; i < strlen(Message); i++)
        {
            if(Message[i] >= 'a' && Message[i] <= 'z')
            {
                Decrypt[i] = LowerDict[Message[i] - 'a'];
            }
            else if(Message[i] >= 'A' && Message[i] <= 'Z')
            {
                Decrypt[i] = UpperDict[Message[i] - 'A'];
            }
            else
            {
                Decrypt[i] = Message[i];
            }
        }
        Decrypt[i] = 0;
        puts(Decrypt);
    }

    return 0;
}

