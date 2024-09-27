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
symbol_t *new_symbol;
size_t new_freq;
if (!priority_queue || priority_queue->size < 2)
{
return (0); }
left_node = (binary_tree_node_t *) heap_extract(priority_queue);
right_node = (binary_tree_node_t *) heap_extract(priority_queue);
if (!right_node || !left_node)
{
return (0); }
new_freq = ((symbol_t *) left_node->data)->freq +
((symbol_t *) right_node->data)->freq;
new_symbol = symbol_create(-1, new_freq);
if (!new_symbol)
{
free(right_node);
free(left_node);
return (0); }
new_node = binary_tree_node(NULL, new_symbol);
if (!new_node)
{
free(right_node);
free(left_node);
free(new_symbol);
return (0); }
new_node->left = left_node;
new_node->right = right_node;
left_node->parent = new_node;
right_node->parent = new_node;
if (!heap_insert(priority_queue, new_node))
{
free(new_node);
free(new_symbol);
return (0); }
return (1);
}

