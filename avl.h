/*
 * avl.h
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

#ifndef AVL_H_
#define AVL_H_

struct node
{
	int key;
	struct node *right;
	struct node *left;
	struct node *parent;
	//int height;
};

struct AVL
{
	struct node *root;
	int number_node;
};

struct AVL * construct_tree();
void insert(struct AVL *avl, int key);
void inorder(struct node *root);
void preorder(struct node *root);
int height_tree(struct AVL * avl);

#endif /* AVL_H_ */
