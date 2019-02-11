#include <stdio.h>
#include <stdlib.h>

// 1
int simpleHash(char* arr)
{
	int hash = 0;

	for (char* i = arr; *i != '\0'; i++)
	{
		hash += *i;
	}

	return hash;
}

// 2
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
} Node;

void insert(Node** Tree, int value)
{
	Node* temp = NULL;

	if (*Tree == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		*Tree = temp;
		return;
	}
	
	temp = *Tree;

	if (value > temp->data)
	{
		insert(&temp->right, value);
	}
	else //if (value <= temp->data)
	{
		insert(&temp->left, value);
	}
}

void preOrderTraversal(Node* Tree)
{
	if (Tree != NULL)
	{
		printf("%d ", Tree->data);
		preOrderTraversal(Tree->left);
		preOrderTraversal(Tree->right);
	}
}

void inOrderTraversal(Node* Tree)
{
	if (Tree != NULL)
	{
		inOrderTraversal(Tree->left);
		printf("%d ", Tree->data);
		inOrderTraversal(Tree->right);
	}
}

void postOrderTraversal(Node* Tree)
{
	if (Tree != NULL)
	{
		postOrderTraversal(Tree->left);
		postOrderTraversal(Tree->right);
		printf("%d ", Tree->data);
	}
}

int Find(Node* Tree, int value)
{
	if (Tree != NULL)
	{
		if (value == Tree->data)
		{
			return 1; // return true
		}
		else if (value < Tree->data)
		{
			return Find(Tree->left, value);
		}
		else if (value > Tree->data)
		{
			return Find(Tree->right, value);
		}
	}
	else
	{
		return 0; // return false
	}
}

void printTree(Node* Tree)
{
	if (Tree != NULL)
	{
		printf("%d", Tree->data);

		if (Tree->left == NULL && Tree->right == NULL)
			return;

		printf("(");
		if (Tree->left != NULL)
		{
			printTree(Tree->left);
		}
		else
		{
			printf("NULL");
		}

		printf(",");
		
		if (Tree->right != NULL)
		{
			printTree(Tree->right);
		}
		else
		{
			printf("NULL");
		}
		printf(")");
	}
}


int main()
{
	// 1
	char* arr = "Hello, world 2019!";
	printf("1) %d\n", simpleHash(arr));

	// 2
	Node* Tree = NULL;

	insert(&Tree, 5);
	insert(&Tree, 9);
	insert(&Tree, 4);
	insert(&Tree, 1);
	insert(&Tree, 8);
	insert(&Tree, 10);
	insert(&Tree, 12);

	printf("\n2) Binary Tree:\n");
	printTree(Tree);

	printf("\nPre-Order: ");
	preOrderTraversal(Tree);
	printf("\nIn-Order: ");
	inOrderTraversal(Tree);
	printf("\nPost-Order: ");
	postOrderTraversal(Tree);

	printf("\n");

	int a = 12, b = 37;
	if (Find(Tree, a))
		printf("\nTree contains %d", a);
	else
		printf("\nTree does not contain %d", a);
	if (Find(Tree, b))
		printf("\nTree contains %d", b);
	else
		printf("\nTree does not contain %d", b);

	return 0;
}