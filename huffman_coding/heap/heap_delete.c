#include <stdlib.h>
#include "heap.h"

void recursive_free(binary_tree_node_t *node, void (*free_data)(void *))
{
if (!node)
{
return;
}
recursive_free(node->left, free_data);
recursive_free(node->right, free_data);
free_data(node->data);
free(node);
}

/**
 * heap_delete - deallocates a heap
 * @heap: pointer to heap to delete
 * @free_data: pointer to function for freeing node's content
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
if (!heap || !free_data)
{
return;
}

recursive_free(heap->root, free_data);
free(heap);
}
