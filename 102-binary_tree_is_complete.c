#include "binary_trees.h"

/**
 * binary_tree_size - The size of a binary tree to measure
 * @tree: root node from which to measure
 * Return: if tree is 0 return NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
/**
 * check_bt_complete - recursively checks if binary tree is complete.
 * @tree: root node from which to measure
 * @i: iterator to mimic an array index
 * @size: total number of nodes in tree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 */
int check_bt_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if ((tree->left && (2 * i) + 1 >= size) ||
	    !check_bt_complete(tree->left, (2 * i) + 1, size))
		return (0);

	if ((tree->right && (2 * i) + 2 >= size) ||
	    !check_bt_complete(tree->right, (2 * i) + 2, size))
		return (0);

	return (1);
}

/**
 * binary_tree_is_complete - calls recursive helper to see if binary tree is
 * complete
 * @tree: root of tree
 * Return: 1 if `tree` is complete, 0 if not or `tree` is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bt_complete(tree, 0, binary_tree_size(tree)));
}
