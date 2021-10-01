#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Stack
{
	struct Node* tree_ptr;
	int indicator;
	struct Stack* next;
};

struct Node* root = NULL;
struct Stack* top = NULL;
struct Stack* bottom = NULL;

void push(struct Node* tree_pointer);
void pop();
struct Node* new_node(int value);
struct Node* insert_node(int value, struct Node* current);
struct Node* deletion(int value, struct Node* current);
void create_tree();
void preorder(struct Node* current);
void inorder();
int height(struct Node* current);
int internal_node(struct Node* current);
int external_node(struct Node* current);

int main()
{
	int choice;
	int data;
	int option;
	do
	{
    	cout<<"Tree Operations Menu :-\n";
    	cout<<"1. Creation of Binary Search Tree\n";
    	cout<<"2. Display Binary Search Tree in preorder\n";
    	cout<<"3. Insert new node in Binary Search Tree\n";
    	cout<<"4. Delete a node from Binary Search Tree\n";
    	cout<<"5. Display height of Binary Search Tree\n";
    	cout<<"6. Display node count\n";
    	cout<<"7. Preorder traversal\n";
    	cout<<"8. Inorder traversal\n";
    	cin>>option;
    	switch(option)
    	{
        	case 1: create_tree();
                	break;
        	case 2: cout<<"Displaying binary search tree in preorder :- \n";
                	preorder(root);
                	cout<<"\n";
                	break;
        	case 3: cout<<"Enter the value you want to insert into the tree ";
                	cin>>data;
                	root = insert_node(data, root);
                	break;
        	case 4: cout<<"Enter the value you want to delete from the tree ";
                	cin>>data;
                	root = deletion(data, root);
                	break;
        	case 5: cout<<"The height of the Binary Search tree is "<<height(root)<<"\n";
                	break;
        	case 6: cout<<"The no of internal nodes are "<<internal_node(root);
                	cout<<" and the no of external nodes are "<<external_node(root)<<"\n";
                	break;
        	case 7: cout<<"The Binary Search tree traversed in preorder is :- \n";
                	preorder(root);
                	cout<<"\n";
                	break;
        	case 8: //Here the traversal is done by iterative method istead of recursive
                	cout<<"The Binary Search tree traversed in inorder is :- \n";
                	inorder();
                	cout<<"\n";
                	break;
        	default:cout<<"Please select a valid option";
    	}
    	cout<<"Do you want to continue(Press 1 for yes and 0 for no) ? ";
    	cin>>choice;
	}while(choice == 1);
}

void push(struct Node* tree_pointer)
{
	struct Stack* temp = (struct Stack* )malloc(sizeof(struct Stack));
	temp->tree_ptr = tree_pointer;
	temp->indicator = 0;
	if(top == NULL)
	{
    	bottom = temp;
	}
	else
	{
    	top->next = temp;
	}
	top = temp;
	top->next = NULL;
}

void pop()
{
	if(top != bottom)
	{
    	struct Stack* temp = bottom;
    	while(temp->next != top)
    	{
        	temp = temp->next;
    	}
    	free(top);
    	top = temp;
    	top->next = NULL;
	}
	else
	{
    	free(top);
    	top = NULL;
    	bottom = NULL;
	}
}

struct Node* new_node(int value)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert_node(int value, struct Node* current)
{
	if(current == NULL)
	{
    	return new_node(value);
	}
	if(value < current->data)
	{
    	current->left = insert_node(value, current->left);
	}
	else if(value > current->data)
	{
    	current->right = insert_node(value, current->right);
	}
	return current;
}

struct Node* deletion(int value, struct Node* current)
{
	if(root == NULL)
	{
    	cout<<"The tree is empty there is nothing to delete\n";
    	return NULL;
	}
	if(current == NULL)
	{
    	cout<<"The given data element dosen't exist in the tree\n";
    	return current;
	}
	else if(value < current->data)
	{
    	current->left = deletion(value, current->left);
	}
	else if(value > current->data)
	{
    	current->right = deletion(value, current->right);
	}
	else
	{
    	if(current->right != NULL && current->left != NULL)
    	{
        	struct Node* temp = current->right;
        	while(temp && temp->left != NULL)
        	{
            	temp = temp->left;
        	}
        	current->data = temp->data;
        	current->right = deletion(temp->data, current->right);
    	}
    	else
    	{
        	if(current->left == NULL && current->right == NULL)
        	{
            	struct Node* temp = NULL;
            	free(current);
            	return temp;
        	}
        	else if(current->left != NULL)
        	{
            	struct Node* temp = current->left;
            	free(current);
            	return temp;
        	}
        	else
        	{
            	struct Node* temp = current->right;
            	free(current);
            	return temp;
        	}
    	}
	}
	return current;
}

void create_tree()
{
	int num_nodes;
	int data;
	cout<<"Enter the no of nodes\n";
	cin>>num_nodes;
	cout<<"Enter the space seprated values that you wnat to insert into the binary tree \n";
	for(int i = 0; i < num_nodes; ++i)
	{
    	cin>>data;
    	root = insert_node(data, root);
	}
}

void preorder(struct Node* current)
{
	if(root != NULL)
	{
    	if(current != NULL)
    	{
        	cout<<current->data<<" ";
        	preorder(current->left);
        	preorder(current->right);
    	}
	}
	else
	{
    	cout<<"The tree is empty!";
	}
}

void inorder()
{
	if(root != NULL)
	{
    	push(root);
    	do
    	{
        	if(top->indicator == 0)
       	{
            	top->indicator = 1;
            	if(top->tree_ptr->left != NULL)
            	{
                	push(top->tree_ptr->left);
            	}
        	}
        	else if(top->indicator == 1)
        	{
            	cout<<top->tree_ptr->data<<" ";
            	top->indicator = 2;
            	if(top->tree_ptr->right != NULL)
            	{
                	push(top->tree_ptr->right);
            	}
        	}
        	if(top->indicator == 2)
        	{
            	pop();
        	}
    	} while (top != NULL);
	}
	else
	{
    	cout<<"The tree is empty!";
	}
}

int height(struct Node* current)
{
	if(current == NULL)
	{
    	return 0;
	}
	else
	{
    	int left_height = height(current->left) + 1;
    	int right_height = height(current->right) + 1;
    	if(left_height > right_height)
    	{
        	return left_height;
    	}
    	else
    	{
        	return right_height;
    	}
	}
}

int internal_node(struct Node* current)
{
	if(current == NULL ||(current->left == NULL && current->right == NULL))
	{
    	return 0;
	}
	else
	{
    	return internal_node(current->left) + internal_node(current->right) + 1;
	}
}

int external_node(struct Node* current)
{
	if(current == NULL)
	{
    	return 0;
	}
	else if(current->left == NULL && current->right == NULL)
	{
    	return 1;
	}
	else
	{
    	return external_node(current->left) + external_node(current->right);
	}
}
