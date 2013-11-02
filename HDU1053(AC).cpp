#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int c[256];
int cl[256];
int cc;
char s[10000];
int len;

typedef struct st{
public:
    char ch;
    int c;
    struct st *left;
    struct st *right;

    st()
    {
        ch = 0;
        c = 0;
        left = NULL;
        right = NULL;
    }
}st;

bool operator < (const st &a, const st &b)
{
    return a.c > b.c;
}

priority_queue<st> pq;

void get_depth(st *root, int d)
{
    if(root->ch){
        cl[root->ch] = d;
    }
    if(root->left != NULL){
        get_depth(root->left, d + 1);
    }
    if(root->right != NULL){
        get_depth(root->right, d + 1);
    }
}

void clear_tree(st *root)
{
    if(root != NULL){
        if(root->left != NULL){
            clear_tree(root->left);
            free(root->left);
        }
        if(root->right != NULL){
            clear_tree(root->right);
            free(root->right);
        }
    }
}

int main()
{
    int i;
    st tmp, ta, tb;
    st *root;

    while(gets(s) != NULL && strcmp(s, "END")){
        len = strlen(s);
        memset(c, 0, 256 * sizeof(int));
        memset(cl, 0, 256 * sizeof(int));
        cc = 0;
        for(i = 0; i < len; ++i){
            if(!c[s[i]]){
                ++cc;
            }
            ++c[s[i]];
        }
        if(cc == 1){
            printf("%d %d %.1f\n", 8 * len, len, 8.0);
            continue;
        }
        for(i = 0; i < 256; ++i){
            if(c[i] > 0){
                tmp.c = c[i];
                tmp.ch = i;
                tmp.left = NULL;
                tmp.right = NULL;
                pq.push(tmp);
            }
        }
        /*
        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            printf("%d\n", tmp.c);
        }
        continue;
        */
        for(i = 0; i < cc - 1; ++i){
            ta = pq.top();
            pq.pop();
            tb = pq.top();
            pq.pop();
            tmp = st();
            tmp.c = ta.c + tb.c;
            tmp.ch = 0;
            tmp.left = new st(ta);
            tmp.right = new st(tb);
            pq.push(tmp);
        }
        root = &(pq.top());
        get_depth(root, 0);
        clear_tree(root);
        while(!pq.empty()){
            pq.pop();
        }

        int sum = 0;
        for(i = 0; i < len; ++i){
            sum += cl[s[i]];
        }

        printf("%d %d %.1f\n", 8 * len, sum, 8.0 * len / sum);
    }

    return 0;
}

