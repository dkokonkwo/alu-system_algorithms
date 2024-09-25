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
if (!parent || !data)
{
return (NULL);
}

new_node = (binary_tree_node_t *) malloc(sizeof(binary_tree_node_t));
if (!new_node)
{
return(NULL);
}

new_node->data = data;
new_node->left = NULL;
new_node->right = NULL;
new_node->parent = parent;

return (new_node);
}
