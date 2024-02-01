#include "binary_trees.h"
/**
 * bt_find_lca - recurses to find lowest common ancestor (LCA)
 * @root: node to recursively root to check 
 * @first: first node 
 * @second: second node
 * Return: LCA return NULL
 */
binary_tree_t *bt_find_lca(binary_tree_t *root, const binary_tree_t *first,
			   const binary_tree_t *second)
{
	binary_tree_t *left_search, *right_search;

	if (!root)
		return (NULL);

	if (root == first || root == second)
		return (root);

	left_search = bt_find_lca(root->left, first, second);
	right_search = bt_find_lca(root->right, first, second);

	if (left_search && right_search)
		return (root);

	if (left_search != NULL)
		return (left_search);
	else
		return (right_search);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *root = (binary_tree_t *)first;
	binary_tree_t *root2 = (binary_tree_t *)second;

	if (!first || !second)
		return (NULL);

	while (root->parent)
		root = root->parent;

	while (root2->parent)
		root2 = root2->parent;
	if (root != root2)
		return (NULL);

	return (bt_find_lca(root, first, second));
}
