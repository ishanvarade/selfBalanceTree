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
	struct node * left;
};

struct AVL
{
	struct node *root;
	int number_node;
};

struct AVL * construct_tree();
void insert(struct AVL *avl, int key);

#endif /* AVL_H_ */
