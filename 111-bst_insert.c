#include "binary_trees.h"
/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST to insert the value
 * @value: value of the node to insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *temp;
	binary_tree_t *x;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		x = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)x;
		*tree = new;
	}
	else
	{
		temp = *tree;
		if (value > temp->n)
		{
			if (temp->left)
				new = bst_insert(&temp->left, value);

			else
			{
				x = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->left = (bst_t *)x;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new = bst_insert(&temp->right, value);
			else
			{
				x = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->right = x;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
