#include "binary_trees.h"

size_t heap_tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 *                        to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = heap_tree_size(heap);
	array = malloc(sizeof(int) * (*size));
	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}

/**
 * heap_tree_size - measures the size of a binary tree
 *
 * @tree: is a pointer to the root node of the tree to measure the size
 *
 * Return: size
 */
size_t heap_tree_size(const binary_tree_t *tree)
{
	size_t countnode = 0;

	if (!tree)
		return (0);
	countnode = 1 + heap_tree_size(tree->right) + heap_tree_size(tree->left);

	return (countnode);
}
