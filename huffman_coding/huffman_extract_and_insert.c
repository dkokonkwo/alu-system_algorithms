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
binary_tree_node_t *left, *right, *new_node;
symbol_t *new_symbol;
if (!priority_queue || !priority_queue->size)
{
return (0);
}

while (priority_queue->size != 1)
{
left = (binary_tree_node_t *) heap_extract(priority_queue);
right = (binary_tree_node_t *) heap_extract(priority_queue);

new_symbol = symbol_create('$', left->freq + right->freq);
if (!new_symbol)
{
return (0);
}

new_node = heap_insert(priority_queue, new_symbol);
new_node->left = left;
new_node->right = right;
}
}
