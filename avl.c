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
		(int)(height_tree(node -> right) - height_tree(node -> left)) \

struct AVL * construct_tree()
{
	struct AVL *avl = (struct AVL *)malloc(sizeof (struct AVL));
	avl -> root = NULL;
	avl -> number_node = 0;
	return avl;
}

void bst_insert(struct AVL *avl, int key)
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
		return ;
	}


	while(1)
	{
		if (p -> key > newNode -> key)
		{
			if (NULL == p -> left)
			{
				p -> left = newNode;
				newNode -> parent = p;



				return;
			}
			p = p -> left;

		}
		else if(p -> key < newNode -> key)
		{
			if (NULL == p -> right)
			{

				newNode -> parent = p;
				p -> right = newNode;
				return ;
			}
			p = p -> right;
		}
		else
		{
			// Equal key are not allower in BST
			return ;
		}
	}
}

int height_tree(struct node * root)
{
	if (root)
	{
		int lh = height_tree(root -> left);
		int rh = height_tree(root -> right);
		return 1 + (lh > rh ? lh : rh);
	}
	return 0;
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

void right_rotation(struct node *N)
{
	struct node *left_child = N -> left;
	N -> left = left_child -> right;
	N -> left -> parent = N;

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
	N -> right -> parent = N;

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

void insert(struct AVL * avl, int key)
{

}

void balancing(struct node *N, int bal)
{
	if (N -> parent)
	{

	}
}
