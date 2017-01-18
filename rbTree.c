/*
 * rbTree.c
 *
 *  Created on: 17-Jan-2017
 *      Author: ishan
 */

#include <stdlib.h>
#include "rbTree.h"


struct node * bst_insert(struct rbTree *rb_tree, int key)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> key = key;
	newNode -> right = NULL;
	newNode -> left = NULL;
	newNode -> parent = NULL;

	++rb_tree -> number_node;
	struct node *p = rb_tree -> root;
	if (rb_tree -> root == NULL)
	{
		rb_tree -> root = newNode;
		rb_tree -> root -> parent = NULL;
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


