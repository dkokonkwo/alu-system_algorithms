#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - builds a huffman tree
 * @data: array of characters
 * @freq: array containing associated frequencies
 * @size: size of both arrays
 * Return: root node of the array or NULL on failure
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
heap_t *priority_queue;
int success;
if (!data || !freq || size == 0)
{
return (NULL);
}

priority_queue = huffman_priority_queue(data, freq, size);
if (!priority_queue)
{
return (NULL);
}

while (priority_queue->size > 1)
{
success = huffman_extract_and_insert(priority_queue);
if (!success)
{
return (NULL);
}
}

return ((binary_tree_node_t *) heap_extract(priority_queue));
}

