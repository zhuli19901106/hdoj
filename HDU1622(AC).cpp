#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef struct Node{
public:
	int key;
	struct Node *left;
	struct Node *right;
	Node(const int _key = -1)
	{
		key = _key;
		left = NULL;
		right = NULL;
	}
}Node;
Node *root;
queue<Node *> qq;

void DeleteTree(Node *root)
{
	if(!root){
		return;
	}
	if(root->left){
		DeleteTree(root->left);
	}
	if(root->right){
		DeleteTree(root->right);
	}
	free(root);
}

bool check_complete(const Node *root)
{
	bool res1, res2;

	if(!root){
		return true;
	}
	if(root->key == -1){
		return false;
	}
	if(root->left){
		res1 = check_complete(root->left);
		if(root->right){
			if(res1){
				res2 = check_complete(root->right);
				return res2;
			}else{
				return false;
			}
		}else{
			return res1;
		}
	}else{
		if(root->right){
			res2 = check_complete(root->right);
			return res2;
		}else{
			return true;
		}
	}
}

int main()
{
	char s[500];
	int i, key;
	bool terminate, complete;
	Node *ptr;
	
	terminate = false;
	while(true){
		root = new Node();
		complete = true;
		while(!(terminate = (scanf("%s", s) != 1))){
			if(strcmp(s, "()") == 0){
				break;
			}
			sscanf(s + 1, "%d", &key);
			i = 1;
			while(s[i] != ','){
				++i;
			}
			++i;
			ptr = root;
			while(s[i] != ')'){
				if(s[i] == 'L'){
					if(ptr->left){
						ptr = ptr->left;
					}else{
						ptr->left = new Node();
						ptr = ptr->left;
					}
				}else if(s[i] == 'R'){
					if(ptr->right){
						ptr = ptr->right;
					}else{
						ptr->right = new Node();
						ptr = ptr->right;
					}
				}
				++i;
			}

			if(ptr->key != -1){
				complete = false;
			}else{
				ptr->key = key;
			}
		}
		if(terminate){
			break;
		}

		if(!complete){
			printf("not complete\n");
			DeleteTree(root);
			root = NULL;
			continue;
		}else{
			complete = check_complete(root);
		}
		if(!complete){
			printf("not complete\n");
			DeleteTree(root);
			root = NULL;
			continue;
		}

		qq.push(root);
		while(!qq.empty()){
			ptr = qq.front();
			qq.pop();
			if(ptr == root){
				printf("%d", ptr->key);
			}else{
				printf(" %d", ptr->key);
			}
			if(ptr->left){
				qq.push(ptr->left);
			}
			if(ptr->right){
				qq.push(ptr->right);
			}
		}
		printf("\n");

		DeleteTree(root);
		root = NULL;
		while(!qq.empty()){
			qq.pop();
		}
	}

	return 0;
}
