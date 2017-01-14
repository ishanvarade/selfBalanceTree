/*
 * test.c
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

//Ishan varade
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
	struct AVL * avl = construct_tree();
	bst_insert(avl, 7348);
	bst_insert(avl, 2478);
	bst_insert(avl, 7865);
	bst_insert(avl, 75338);
	bst_insert(avl, 78651);
	bst_insert(avl, 78);
	bst_insert(avl, 7898);
	bst_insert(avl, 78);
	bst_insert(avl, 7458);
	bst_insert(avl, 78);
	bst_insert(avl, 128);
	bst_insert(avl, 786);
	bst_insert(avl, 5678);
	bst_insert(avl, 1178);
	bst_insert(avl, 9078);

	inorder(avl -> root);
	int height_avl = height_tree(avl -> root);
	int height_avl_left = height_tree(avl -> root -> left);
	int height_avl_right= height_tree(avl -> root -> right);


	printf("\nHeight: %d\n", height_avl);

	printf("\nLEft Height: %d\n", height_avl_left);

	printf("\nRight Height: %d\n", height_avl_right);

	return 0;
}
