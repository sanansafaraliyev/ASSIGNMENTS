#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* newnode(int value)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->value=value;
	node->left=NULL;
	node->right=NULL;

	return (node);
}

int pathsum(struct Node* iter)
{
	if (iter == NULL)
		return 0;
	int leftsum=pathsum(iter->left);
	int rightsum=pathsum(iter->right);

	return (leftsum >rightsum ? leftsum :rightsum) + iter->value;


}

int main()
{
	struct Node* root=newnode(1);
	root->left=newnode(5);
	root->right=newnode(10);
	root->left->left=newnode(20);
	root->left->right=newnode(4);
	root->right->left=newnode(21);
	root->right->right=newnode(20);

	pathsum(root);

	printf("The highest value of the sum is:%d\n",pathsum(root));



	return 0;
}

