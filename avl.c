/*
 * avl.c
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

#include <stdlib.h>
#include "avl.h"

struct AVL * construct_tree()
{
	struct AVL *avl = (struct AVL *)malloc(sizeof (struct AVL));
	avl -> root = NULL;
	return avl;
}

void bst_insert(struct AVL *avl, int key)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> key = key;
	newNode -> right = NULL;
	newNode -> left = NULL;

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

void inorder(struct AVL *avl);
