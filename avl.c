/*
 * avl.c
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

#define balance(node) \
		(int)(__height_tree(node -> right) - __height_tree(node -> left)) \

struct AVL * construct_tree()
{
	struct AVL *avl = (struct AVL *)malloc(sizeof (struct AVL));
	avl -> root = NULL;
	avl -> number_node = 0;
	return avl;
}

struct node * bst_insert(struct AVL *avl, int key)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> key = key;
	newNode -> right = NULL;
	newNode -> left = NULL;
	newNode -> parent = NULL;

	++avl -> number_node;
	struct node *p = avl -> root;
	if (avl -> root == NULL)
	{
		avl -> root = newNode;
		avl -> root -> parent = NULL;
		return newNode;
	}


	while(1)
	{
		if (p -> key > newNode -> key)
		{
			if (NULL == p -> left)
			{
				p -> left = newNode;
				newNode -> parent = p;
				return newNode ;
			}
			p = p -> left;

		}
		else if(p -> key < newNode -> key)
		{
			if (NULL == p -> right)
			{
				newNode -> parent = p;
				p -> right = newNode;
				return newNode;
			}
			p = p -> right;
		}
		else
		{
			// Equal key are not allower in BST
			return NULL;
		}
	}
}

int __height_tree(struct node * root)
{
	if (root)
	{
		int lh = __height_tree(root -> left);
		int rh = __height_tree(root -> right);
		return 1 + (lh > rh ? lh : rh);
	}
	return 0;
}

int height_tree(struct AVL * avl)
{
	return __height_tree(avl -> root);
}

void inorder(struct node *root)
{
	if (root -> left)
	{
		inorder(root -> left);
	}

	printf("key: %d, balance: %d ", root -> key, balance(root));

	if (root -> right)
	{
		inorder(root -> right);
	}
}

void preorder(struct node *root)
{
	printf("key: %d, balance: %d ", root -> key, balance(root));

	if (root -> left)
	{
		preorder(root -> left);
	}

	if (root -> right)
	{
		preorder(root -> right);
	}
}

void right_rotation(struct node *N)
{
	struct node *left_child = N -> left;
	N -> left = left_child -> right;
	if (N -> left)
	{
		N -> left -> parent = N;
	}

	left_child -> parent = N -> parent;

	if (N -> parent != NULL)
	{
		if (N -> parent -> left == N)
		{
			N -> parent -> left = left_child;
		}
		else
		{
			N -> parent -> right = left_child;
		}
	}

	left_child -> right = N;
	N -> parent = left_child;
}

void left_rotation(struct node *N)
{
	struct node *right_child = N -> right;
	N -> right = right_child -> left;
	if (N -> right)
	{
		N -> right -> parent = N;
	}

	right_child -> parent = N -> parent;

	if (N -> parent != NULL)
	{
		if (N -> parent -> left == N)
		{
			N -> parent -> left = right_child;
		}
		else
		{
			N -> parent -> right = right_child;
		}
	}
	right_child -> left = N;
	N -> parent = right_child;
}

void left_right_rotation(struct node *N)
{
	left_rotation(N -> left);
	right_rotation(N);
}

void right_left_rotation(struct node *N)
{
	right_rotation(N -> right);
	left_rotation(N);
}



void balancing(struct AVL *avl, struct node *N, int bal)
{
	int m = balance(N);
	if (2 == m)
	{
		if (1 == bal)
		{
			left_rotation(N);
		}
		else if (-1 == bal)
		{
			right_left_rotation(N);
		}
		else
		{
			printf("\nE: 1Wrong happen");
		}

		if (N == avl -> root)
		{
			avl -> root = N -> parent;
		}
	}
	else if (-2 == m)
	{
		if (-1 == m)
		{
			right_rotation(N);
		}
		else if (1 == m)
		{
			left_right_rotation(N);
		}
		else
		{
			printf("\nE: 2Wrong happen");
		}

		if (N == avl -> root)
		{
			avl -> root = N -> parent;
		}
	}
	else if (N -> parent)
	{
		balancing(avl, N -> parent, m);
	}
	else
	{
		printf("\nBalancing if over\n");
	}

}

/*ishan is my name*/
void insert(struct AVL * avl, int key)
{
	struct node *N = bst_insert(avl, key);
	balancing(avl, N, 0);
}
