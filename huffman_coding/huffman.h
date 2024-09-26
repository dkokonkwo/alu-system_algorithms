#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unistd.h>
#include "heap.h"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int freq_cmp(void *a, void *b);
binary_tree_node_t* created_nested(char data, size_t freq);
#endif
