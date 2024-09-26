#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * freq_cmp - compare two frequencies
 * @a: first
 * @b: second
 * Return: difference
 */
int freq_cmp(void *a, void *b)
{
symbol_t *a, *b;
a = ((binary_tree_node_t *)a)->data;
b = ((binary_tree_node_t *)b)->data;
return (a->freq - b->freq);
}

/**
 * create_nested - create binary tree node with data as symbol
 * @data: symbol data
 * @freq: symbol frequency
 * Return: created node
 */
binary_tree_node_t* created_nested(char data, size_t freq)
{
binary_tree_node_t *nested;
symbol_t *symbol = symbol_create(data, freq);
if (!symbol)
{
return (NULL);
}

nested = binary_tree_node(NULL, symbol);
if (!nested)
{
return (NULL);
}

return (nested);
}

/**
 * huffman_priority_queue - creates a priority queue for HF coding
 * @data: array of characters
 * @freq: array containing associated frequencies
 * @size: size of both data and freq arrays
 * Return: priority queue
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
binary_tree_node_t *new_node, *current_node;
int i;
heap_t *priority_queue;
if (!data || !freq || !size)
{
return (NULL);
}
priority_queue = heap_create(freq_cmp);
if (!priority_queue)
{
return (NULL);
}
for (i = 0; i < size; i++)
{
new_node = create_nested(data[i], freq[i]);
if (!new_node)
{
free(priority_queue);
return (NULL);
}
current_node = heap_insert(priority_queue, new_node);
}

return (priority_queue);
}
