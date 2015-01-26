#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 20;
typedef long long int LL;
LL a[MAXN];
LL s[MAXN];
LL nn;
int nc;

typedef struct Node{
	struct Node *left;
	struct Node *right;

	Node()
	{
		left = NULL;
		right = NULL;
	}
}Node;
Node *root;

void InorderTraversal(const Node *root)
{
	if(root->left != NULL){
		putchar('(');
		InorderTraversal(root->left);
		putchar(')');
	}
	putchar('X');
	if(root->right != NULL){
		putchar('(');
		InorderTraversal(root->right);
		putchar(')');
	}
}

void FreeTree(Node *root)
{
	if(root != NULL){
		if(root->left != NULL){
			FreeTree(root->left);
		}
		if(root->right != NULL){
			FreeTree(root->right);
		}
		free(root);
	}
}

void ConstructTree(Node *root, LL n1, int nc)
{
	int lc, rc;
	LL sum, nr;
	LL n_l, n_r;
	
	rc = nc - 1;
	sum = 0;
	while(true){
		lc = nc - 1 - rc;
		sum += a[lc] * a[rc];
		if(sum < n1){
			--rc;
		}else{
			break;
		}
	}

	nr = n1 - (sum - a[lc] * a[rc]);
	n_l = (nr - 1) / a[rc] + 1;
	n_r = (nr - 1) % a[rc] + 1;

	if(rc > 0){
		root->right = new Node();
		ConstructTree(root->right, n_r, rc);
	}

	if(lc > 0){
		root->left = new Node();
		ConstructTree(root->left, n_l, lc);
		//To be continued here.
	}
}

int main()
{
	int n;
	LL n1;

	a[0] = 1;
	a[1] = 1;
	for(n = 2; n < MAXN; ++n){
		a[n] = a[n - 1] * (4 * n - 2) / (n + 1);
	}

	s[0] = 0;
	for(n = 1; n < MAXN; ++n){
		s[n] = s[n - 1] + a[n];
	}

	while(scanf("%lld", &nn) == 1 && nn){
		nc = 1;
		while(s[nc] < nn){
			++nc;
		}
		n1 = nn - s[nc - 1];

		root = new Node();
		ConstructTree(root, n1, nc);

		InorderTraversal(root);
		printf("\n");

		FreeTree(root);
		root = NULL;
	}

	return 0;
}
