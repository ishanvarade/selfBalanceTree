/*
 * rbTree.h
 *
 *  Created on: 16-Jan-2017
 *      Author: ishan
 */

/*
 * PROPERTIES of Red Black Tree
 * 1. Every node either red or black.
 * 2. The root is black.
 * 3. Every leaf(NIL) is black.
 * 4. If a node is red, then both its children are black.
 * 5. For each node, all simple path from the node to descendant leaves contain the same number of black nodes.
 */
#ifndef RBTREE_H_
#define RBTREE_H_

enum color
{
	red = 0,
	black
};

struct rbNode
{
	int key;
	enum color color;
	struct rbNode *right;
	struct rbNode *left;
	struct rbNode *parent;
};

struct rbTree
{
	struct rbNode *root;
	int number_node;
};

struct rbTree * construct_tree();
void insert(struct rbTree *rb_tree, int key);
void inorder(struct node *root);
void preorder(struct node *root);
int height_tree(struct rbTree * rb_tree);


#endif /* RBTREE_H_ */
