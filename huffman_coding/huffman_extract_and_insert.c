#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * huffman_extract_and_insert - extracts nodes from pqueue and inserts new one
 * @priority_queue: pointer to priority queue to extract from
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
binary_tree_node_t *new_node, *left_node, *right_node;
symbol_t *new_symbol, *left_symbol, *right_symbol;
if (!priority_queue || !priority_queue->size < 2)
{
return (0);
}

left_symbol = (symbol_t *) heap_extract(priority_queue);
right_symbol = (symbol_t *) heap_extract(priority_queue);
if (!left_symbol || !right_symbol)
{
return (0);
}

left_node = binary_tree_node(NULL, left_symbol);
right_node = binary_tree_node(NULL, right_symbol);
if (!left_node || !right_node)
{
return (0);
}
new_symbol = symbol_create(-1, left_symbol->freq + right_symbol->freq);

new_node = binary_tree_node(NULL, new_symbol);
if (!new_node)
{
return (0);
}
new_node->left = left_node;
new_node->right = right_node;

if (!heap_insert(priority_queue, new_node))
{
return (0);
}

return (1);
}
