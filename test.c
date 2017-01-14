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

	int key;

	while (1)
	{
		printf("*********************************************************\nKey: ");
		scanf("%d", &key);

		insert(avl, key);
		inorder(avl -> root);
		printf("\n");
		preorder(avl -> root);

		printf("\n");
		printf("\nHeight: %d\n",height_tree(avl));
		printf("\n********************************************************\n");

	}

	//inorder(avl -> root);
	return 0;
}
