#include "binary_trees.h"
/**
 * max_size_t - finds larger of two size_t values
 * @a: first value
 * @b: second value 
 * Return: larger size_t value.
 */
size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}
/**
 * binary_tree_height - The height of a binary tree to measure
 * @tree: root node from which to measure, starting at 0
 * Return: NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	return (1 + max_size_t(binary_tree_height(tree->left),
			       binary_tree_height(tree->right)));
}

/**
 * operate_on_level - recurses to a given level (depth) of a binary tree.
 * @tree: root of tree or subtree
 * @level: depth in tree to recurse to, starting at 0 for `root`
 * @func: pointer to function to apply to all nodes at level `lvl`
 */
void operate_on_level(const binary_tree_t *tree, size_t lvl, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (lvl == 0)
		func(tree->n);
	else
	{
		operate_on_level(tree->left, lvl - 1, func);
		operate_on_level(tree->right, lvl - 1, func);
	}
}

/**
 * binary_tree_levelorder - applies function to each node in a binary tree
 * @tree: root of tree or subtree
 * @func: pointer to function to be applied
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_h, x;

	if (!tree || !func)
		return;

	tree_h = binary_tree_height(tree);

	for (x = 0; x <= tree_h; x++)
		operate_on_level(tree, x, func);
}
