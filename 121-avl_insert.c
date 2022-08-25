#include "binary_trees.h"

/**
 * avl_insert - insert a new node in a Binary Search Tree
 * @tree: a pointer to the first node
 * @value: int value
 *
 * Return: If no common ancestor was found return NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	node = avl_recu(tree, value);
	return (node);
}

/**
 * avl_recu - insert a new node in a Binary Search Tree
 * @tree: a pointer to the first node
 * @value: int value
 *
 * Return: If no common ancestor was found return NULL
 */
avl_t *avl_recu(avl_t **tree, int value)
{
	avl_t *new_node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			new_node = avl_recu(&((*tree)->left), value);
			if (new_node)
			{
				balancer(tree, value);
			}
			return (new_node);
		}
	}
	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			new_node = avl_recu(&((*tree)->right), value);
			if (new_node)
			{
				balancer(tree, value);
			}
			return (new_node);
		}
	}
	return (NULL);
}

/**
 * balancer - insert a new node in a Binary Search Tree
 * @node: a pointer to the first node
 * @value: int value
 *
 * Return: If no common ancestor was found return NULL
 */
void balancer(avl_t **node, int value)
{
	int balancer;

	balancer = binary_tree_balance(*node);

	if (balancer > 1 && value < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}
	if (balancer < -1 && value > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (balancer > 1 && value > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balancer < -1 && value < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}
