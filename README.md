# 0x1D. C - Binary trees


`C`
`Group project`
`Algorithm`
`Data structure`

## Data structures
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree
`typedef struct binary_tree_s bst_t;`
### AVL Tree
`typedef struct binary_tree_s avl_t;`
### Max Binary Heap
`typedef struct binary_tree_s heap_t;`

**Note**: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

## Print function
To match the examples in the tasks, you are given [this function](https://github.com/holbertonschool/0x1C.c)

This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction


# Tasks
## 0. New node

Write a function that creates a binary tree node

  * Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
  * Where `parent` is a pointer to the parent node of the node to create
  * And `value` is the value to put in the new node
  * When created, a node does not have any child
  * Your function must return a pointer to the new node, or `NULL`  on failure
  
```
alex@/tmp/binary_trees$ cat 0-main.c 
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```
**Repo:**

  * GitHub repository: `binary_trees`
  * File: `0-binary_tree_node.c`

## 1. Insert left

Write a function that inserts a node as the left-child of another node

   * Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)`;
   * Where `parent` is a pointer to the node to insert the left-child in
   * And `value` is the value to store in the new node
   * Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
   * If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

```
alex@/tmp/binary_trees$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
alex@/tmp/binary_trees$
```


**Repo:**

   * GitHub repository: `binary_trees`
   * File: `1-binary_tree_insert_left.c`




## 2. Insert right


Write a function that inserts a node as the right-child of another node

   * Prototype:`binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)`;
   * Where `parent` is a pointer to the node to insert the right-child in
   * And `value` is the value to store in the new node
   * Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
   * If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

```
alex@/tmp/binary_trees$ cat 2-main.c 
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
alex@/tmp/binary_trees$ ./2-right 
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
alex@/tmp/binary_trees$
```
**Repo:**

   * GitHub repository: `binary_trees`
   * File: `2-binary_tree_insert_right.c`
