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

void right_rotation(struct rbNode *node)
{
	struct node *left_child = node -> left;
	node -> left = left_child -> right;
	if (node -> left)
	{
		node -> left -> parent = node;
	}

	left_child -> parent = node -> parent;

	if (node -> parent != NULL)
	{
		if (node -> parent -> left == node)
		{
			node -> parent -> left = left_child;
		}
		else
		{
			node -> parent -> right = left_child;
		}
	}

	left_child -> right = node;
	node -> parent = left_child;
}

void left_rotation(struct rbNode *node)
{
	struct node *right_child = node -> right;
	node -> right = right_child -> left;
	if (node -> right)
	{
		node -> right -> parent = node;
	}

	right_child -> parent = node -> parent;

	if (node -> parent != NULL)
	{
		if (node -> parent -> left == node)
		{
			node -> parent -> left = right_child;
		}
		else
		{
			node -> parent -> right = right_child;
		}
	}
	right_child -> left = node;
	node -> parent = right_child;
}

void rb_fix(struct rbTree *rb_tree, struct rbNode * node)
{
	while (node -> parent && node -> parent -> color == red)
	{
		if (node -> parent -> parent &&
				node -> parent -> parent -> left == node -> parent)
		{
			if (node -> parent -> parent -> right &&
					node -> parent -> parent -> right -> color == red)
			{
				struct rbNode *y = node -> parent -> parent -> right;
				y -> color = black;
				node -> parent -> parent -> color = red;
				node -> parent -> color = black;
				node = node -> parent -> parent;
			}
			else  if (node -> parent -> right == node)
			{
				node = node -> parent;
				left_rotation(node);
				node -> parent -> color = black;
				node -> parent -> parent -> color = red;
				right_rotation(node -> parent -> parent);
			}
		}
		else if (node -> parent -> parent &&
				node -> parent -> parent -> right == node -> parent)
		{
			if (node -> parent -> parent -> left &&
					node -> parent -> parent -> left -> color == red)
			{
				struct rbNode *y = node -> parent -> parent -> left;
				y -> color = black;
				node -> parent -> color = black;
				node -> parent -> parent -> color = red;
				node = node -> parent -> parent;
			}
			else if (node -> parent -> left == node)
			{
				node = node -> parent;
				right_rotation(node);
				node -> parent -> color = black;;
				node -> parent -> parent -> color = red;
				left_rotation(node -> parent -> parent);
			}
		}

	}
}
