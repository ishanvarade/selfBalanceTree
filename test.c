/*
 * test.c
 *
 *  Created on: 14-Jan-2017
 *      Author: ishan
 */

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
	struct AVL * avl = construct_tree();
	insert(avl, 7348);
	insert(avl, 2478);
	insert(avl, 7865);
	insert(avl, 75338);
	insert(avl, 78651);
	insert(avl, 78);
	insert(avl, 7898);
	insert(avl, 78);
	insert(avl, 7458);
	insert(avl, 78);
	insert(avl, 128);
	insert(avl, 786);
	insert(avl, 5678);
	insert(avl, 1178);
	insert(avl, 9078);

	inorder(avl -> root);
	return 0;
}
