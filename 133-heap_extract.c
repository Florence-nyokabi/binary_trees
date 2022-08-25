#include "binary_trees.h"

/**
 * enqueue_item_4 - Adds an item to a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 * @item: The item to add to the queue.
 */
void enqueue_item_4(heap_t **queue_h, heap_t **queue_t,
	int *n, void *item)
{
	heap_t *new_node;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		new_node = malloc(sizeof(heap_t));
		if (new_node == NULL)
			return;
		new_node->left = *queue_t;
		new_node->right = NULL;
		new_node->n = (item != NULL ? ((heap_t *)item)->n : -1);
		new_node->parent = (heap_t *)item;
		if (*queue_h == NULL)
			*queue_h = new_node;
		if (*queue_t != NULL)
			(*queue_t)->right = new_node;
		*queue_t = new_node;
		if (n != NULL)
			(*n)++;
	}
}

/**
 * dequeue_item_4 - Removes an item from a queue.
 * @queue_h: A pointer to the queue's head.
 * @queue_t: A pointer to the queue's tail.
 * @n: A pointer to the queue's size value.
 *
 * Return: The value of the removed queue.
 */
heap_t *dequeue_item_4(heap_t **queue_h,
	heap_t **queue_t, int *n)
{
	heap_t *tmp0;
	heap_t *tmp1;
	heap_t *node = NULL;

	if ((queue_h != NULL) && (queue_t != NULL))
	{
		tmp0 = *queue_h;
		if (tmp0 != NULL)
		{
			node = tmp0->parent;
			if (tmp0->right != NULL)
			{
				tmp1 = tmp0->right;
				tmp1->left = NULL;
				*queue_h = tmp1;
				free(tmp0);
			}
			else
			{
				free(tmp0);
				*queue_h = NULL;
				*queue_t = NULL;
			}
			if (n != NULL)
				(*n)--;
		}
	}
	return (node);
}

/**
 * get_last_heap_node - Gets the last level order node \
 * in a max binary heap tree.
 * @root: The root of the max binary heap tree.
 *
 * Return: A pointer to the last level order node, otherwise NULL.
 */
heap_t *get_last_heap_node(const heap_t *root)
{
	heap_t *head = NULL, *tail = NULL;
	heap_t *last_node = NULL, *current = NULL;
	int n = 0;

	if (root != NULL)
	{
		enqueue_item_4(&head, &tail, &n, (void *)root);
		while (n > 0)
		{
			current = head;
			if (current->parent != NULL)
			{
				last_node = current->parent;
				if (current->parent->left != NULL)
				{
					enqueue_item_4(&head, &tail, &n, (void *)(current->parent->left));
				}
				if (current->parent->right != NULL)
				{
					enqueue_item_4(&head, &tail, &n, (void *)(current->parent->right));
				}
			}
			dequeue_item_4(&head, &tail, &n);
		}
		while (n > 0)
			dequeue_item_4(&head, &tail, &n);
	}
	return (last_node);
}

/**
 * swap_tree_node_with_parent_1 - Swaps a node in a \
 * max binary heap tree with its parent.
 * @node: A pointer to the node's address.
 * @root: A pointer to the root of the tree.
 */
void swap_tree_node_with_parent_1(heap_t **node, heap_t **root)
{
	heap_t *node_copy, *p, *tmp0, *l, *r;

	if ((node != NULL) && ((*node)->parent != NULL) && (root != NULL))
	{
		p = (*node)->parent, node_copy = *node, tmp0 = (*node)->parent->parent;
		l = (*node)->left, r = (*node)->right;
		if ((*node)->parent->left != *node) /* swap from the right */
		{
			if ((tmp0 != NULL) && (tmp0->left == (*node)->parent))
				tmp0->left = *node;
			if ((tmp0 != NULL) && (tmp0->right == (*node)->parent))
				tmp0->right = *node;
			if ((*node)->parent->left != NULL)
				(*node)->parent->left->parent = node_copy;
			(*node)->parent = tmp0, (*node)->left = p->left, (*node)->right = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		else /* swap from the left */
		{
			if ((tmp0 != NULL) && (tmp0->left == p))
				tmp0->left = *node;
			if ((tmp0 != NULL) && (tmp0->right == p))
				tmp0->right = *node;
			if ((*node)->parent->right != NULL)
				(*node)->parent->right->parent = *node;
			(*node)->parent = tmp0, (*node)->right = p->right, (*node)->left = p;
			p->parent = node_copy, p->left = l, p->right = r;
		}
		if (l != NULL)
			l->parent = p;
		if (r != NULL)
			r->parent = p;
		if (tmp0 == NULL)
			*root = node_copy;
	}
}

/**
 * heap_extract - Extracts the root node of a max binary heap tree
 * @root: A pointer to the address of the tree's root node.
 *
 * Return: The value of the extracted node, otherwise NULL.
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *node_l, *node_r, *tmp, *dummy;
	int value = 0, val_l, val_r;

	if ((root != NULL) && (*root != NULL))
	{
		node = *root;
		node_l = node->left;
		node_r = node->right;
		value = node->n;
		tmp = get_last_heap_node(node);
		*root = ((tmp != NULL) && (tmp->parent != NULL) ? tmp : NULL);
		if ((tmp != NULL) && (tmp->parent != NULL))
		{
			if (tmp->parent->left == tmp)
				tmp->parent->left = NULL;
			if (tmp->parent->right == tmp)
				tmp->parent->right = NULL;
			tmp->parent = NULL;
			tmp->left = (node_l != tmp ? node_l : NULL);
			tmp->right = (node_r != tmp ? node_r : NULL);
			if ((node_l != NULL) && (node_l != tmp))
				node_l->parent = tmp;
			if ((node_r != NULL) && (node_r != tmp))
				node_r->parent = tmp;
			while (tmp != NULL)
			{
				val_l = tmp->left != NULL ? tmp->left->n : tmp->n;
				val_r = tmp->right != NULL ? tmp->right->n : tmp->n;
				dummy = val_l > val_r ? tmp->left : tmp->right;
				if ((dummy != NULL) && (dummy->n > dummy->parent->n))
					swap_tree_node_with_parent_1(&dummy, root);
				else
					break;
			}
		}
		free(node);
	}
	return (value);
}
