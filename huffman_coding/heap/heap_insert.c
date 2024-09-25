#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @data: data to be stored in the node
 * Return: pointer to created node or NULL on failure
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
binary_tree_node_t *new_node;
if (!data)
{
return (NULL);
}

new_node = (binary_tree_node_t *) malloc(sizeof(binary_tree_node_t));
if (!new_node)
{
return (NULL);
}

new_node->data = data;
new_node->left = NULL;
new_node->right = NULL;
new_node->parent = parent;

return (new_node);
}

/**
 * compare - compare nodes
 * @heap - min binary heap
 * @node - node to compare with
 * Return - smallest node
 */
binary_tree_node_t *compare(heap_t *heap,
binary_tree_node_t current_node, binary_tree_node_t *new_node)
{
binary_tree_node_t *left;
binary_tree_node_t *right;
if (heap->data_cmp(current_node, new_node) >= 0)
{
return (current_node);
}

left = compare(heap, current_node->left, new_node);
right = compare(heap, current_node->right, new_node);

return (heap->data_cmp(left, right) < 0 ? left : right);
}

/**
 * heap_insert - inserts a value to a min binary heap
 * @heap: pointer to the heap
 * @data: sata to store in the new node
 * Return: pointer to created node or NULL on failure
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
binary_tree_node_t *new_node;
binary_tree_node_t *current_node;
if (!heap || !data)
{
return (NULL);
}

new_node = binary_tree_node(NULL, data);
if (!heap->root)
{
heap->root = new_node;
}
else
{
current_node = compare(heap, current_node, new_node);
current_node->parent->left = new_node;
new_node->parent = current_node->parent;
new_node->left = current_node->left;
new_node->right = current_node;
current_node->left = NULL;
current_node->parent = new_node;
}

heap->size++;
return(new_node);
}
