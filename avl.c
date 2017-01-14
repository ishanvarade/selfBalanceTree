/*
 * avl.c
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

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

	++avl -> number_node;
	struct node *p = avl -> root;
	if (avl -> root == NULL)
	{
		avl -> root = newNode;
		return ;
	}


	while(1)
	{
		if (p -> key > newNode -> key)
		{
			if (NULL == p -> left)
			{
				p -> left = newNode;
				return;
			}
			p = p -> left;

		}
		else
		{
			if (NULL == p -> right)
			{
				p -> right = newNode;
				return ;
			}
			p = p -> right;
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

	printf("%d, ", root -> key);

	if (root -> right)
	{
		inorder(root -> right);
	}
}

void right_rotation(struct node *N)
{
	struct node *left_child = N -> left;
	N -> left = left_child -> right;
	left_child -> right = N;
}

void left_rotation(struct node *N)
{
	struct node *right_child = N -> right;
	N -> right = right_child -> right;
	right_child -> left = N;
}

