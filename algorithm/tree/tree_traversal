// Tree traversal O(n)
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	char data;
	TreeNode *parent;
	TreeNode *left, *right;
};

void preorder(TreeNode* node){
	if(node == NULL) return;
	printf("%c", node->data); // visit
	preorder(node->left);
	preorder(node->right);
}

void inorder(TreeNode* node){
	if(node == NULL) return;
	inorder(node->left);
	printf("%c", node->data); // visit
	inorder(node->right);
}

void postorder(TreeNode* node){
	if(node == NULL) return;
	postorder(node->left);
	printf("%c", node->data); // visit
	postorder(node->right);
}

int main(){

}
