#include "binary_trees.h"

/**
 * binary_tree_rotate_right - binary tree to rotate right to the new root
 * @tree: tree to right rotate
 * Return: pointer to new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree)
		return (NULL);

	pivot = tree->left;

	tree->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}

	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}
