// binary tree program 
// includes functions such as add, delete and search

#include<stdlib.h>             			 // calls standard libraries
#include<stdio.h>

struct bin_tree     				 // defines the tree and the left and right pointer
{
int data;
struct bin_tree * right, * left;
};

typedef struct bin_tree node;			 // makes the tree into a node

void insert(node ** tree, int val)		 // clears values
{
	
	node *temp = NULL;
	if(!(*tree))				 // checks to see if the tree is empty then roots node

	{ 

        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;	 // when left/right most node is null insert new node
        temp->data = val;			 
        *tree = temp;
        return;

	}

if(val < (*tree)->data) 		         // compares inserted node values are lesser than  root 	
	{

	insert(&(*tree)->left, val);		 // repeatally use insert while there is a non-NUll left node  

	}	

else if(val > (*tree)->data)			 // compares inserted node values are greater than root
{

	insert(&(*tree)->right,val);		 // repeatally use insert while there is a non-Null right node

}

}

void print_preorder(node * tree)

{
        if (tree)
       
        {

        printf("%d\n",tree->data);

        print_preorder (tree->left);

        print_preorder (tree->right);

        }
        
}

void print_inorder(node * tree)

{
        if (tree)
        {

                print_inorder(tree->left);

                printf("%d\n",tree->data);

                print_inorder(tree->right);

        }

}

void print_postorder(node * tree)

{

        if (tree)

        {

                print_postorder(tree->left);

                print_postorder(tree->right);

                printf("%d\n",tree->data);

        }

}

void deltree(node * tree)

{

        if (tree)

        {

                deltree(tree->left);
                
                deltree(tree->right);

                free(tree);

        }

}

node* search(node ** tree, int val)

{

        if(!(*tree))

        {

                return NULL;

        }

        if(val < (*tree)->data)

        {

                search(&((*tree)->left), val);

        }

        else if (val > (*tree)->data)

        {

                search(&((*tree)->right), val);

        }

        else if (val == (*tree)->data)

        {

                return *tree;

        }

}

int  main()

{

        node*root;

        node*tmp;

        
        root = NULL;

        // node values in tree

        insert(&root, 9);

        insert(&root, 5);

        insert(&root, 15);

        insert(&root, 12);

        insert(&root, 17);

        insert(&root, 2);

        insert(&root, 69);

        insert(&root, 13);

        // printing values of tree

        printf("Pre Order Display\n");

        print_preorder(root);

        printf("In Order Display\n");

        print_inorder(root);

        printf("Post Order Display\n");

        print_postorder(root);

        // search nodes in tree

        tmp = search(&root, 12);

        if(tmp)

        {

                printf("Search node=%d\n", tmp->data);

        }

        else

        {
                printf("data not found in tree.\n");

        }


        // deleting nodes of tree

        deltree(root);

}

        


