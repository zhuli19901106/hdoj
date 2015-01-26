#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
public:
	int key;
	struct st *left;
	struct st *right;

	st(int _key)
	{
		key = _key;
		left = NULL;
		right = NULL;
	}
}st;

int pre[1005];
int ino[1005];
int p[1005];
int n;
vector<int> vv;

void clear_tree(st *&root)
{
	if(!root){
		return;
	}else{
		if(root->left){
			clear_tree(root->left);
			root->left = NULL;
		}
		if(root->right){
			clear_tree(root->right);
			root->right = NULL;
		}
		delete root;
		root = NULL;
	}
}

void post_order(st *root)
{
	if(!root){
		return;
	}else{
		if(root->left){
			post_order(root->left);
		}
		if(root->right){
			post_order(root->right);
		}
		vv.push_back(root->key);
	}
}

void process(st *&root, int pll, int prr, int ill, int irr)
{
	int len1, len2;
	//The left subtree
	len1 = p[root->key] - ill;
	len2 = irr - p[root->key];

	if(p[root->key] > ill){
		root->left = new st(pre[pll + 1]);
		process(root->left, pll + 1, pll + len1, ill, p[root->key] - 1);
	}

	//The right subtree
	if(p[root->key] < irr){
		root->right = new st(pre[pll + len1 + 1]);
		process(root->right, pll + len1 + 1, prr, p[root->key] + 1, irr);
	}
}

int main()
{
	int i;
	struct st *root;
	
	while(scanf("%d", &n) == 1){
		for(i = 1; i <= n; ++i){
			scanf("%d", &pre[i]);
		}
		for(i = 1; i <= n; ++i){
			scanf("%d", &ino[i]);
			p[ino[i]] = i;
		}
		root = new st(pre[1]);
		process(root, 1, n, 1, n);
		vv.clear();
		post_order(root);
		printf("%d", vv[0]);
		for(i = 1; i < n; ++i){
			printf(" %d", vv[i]);
		}
		printf("\n");
		vv.clear();
		clear_tree(root);
		delete root;
		root = NULL;
	}

	return 0;
}
