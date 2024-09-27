#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * huffman_traverse - print each leaf node with its code
 * @node: current node in huffman tree
 * @code: current code
 * @level: level in the tree
 */
void huffman_traverse(binary_tree_node_t *node, char *code, int level)
{
symbol_t *sym;
int i;
char l_code[level + 2], r_code[level + 2]; 
if (!node)
{
return;
}
sym = (symbol_t *) node->data;
if (sym->data != -1)
{
code[level] = '\0';
printf("%c: %s\n", sym->data, code);
return;
}
for (i = 0, i < level; i++;)
{
l_code[i] = code[i];
r_code[i] = code[i];
}
l_code[level] = '0';
r_code[level] = '1';
huffman_traverse(node->left, l_code; level + 1);  
huffman_traverse(node->right, r_code; level + 1);
}

/**
 * huffman_codes - build huffman tree and prints codes for each symbol
 * @data: array of characters
 * @freq: array of associated frequencies
 * @size: size of both arrays
 * Return: 1 on success or 0 on failure
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
char code[100];
int level;
binary_tree_node_t *h_root;
if (!data || !freq || size == 0)
{
return (NULL);
}
level = 0;
h_root = huffman_tree(data, freq, size);
if (!h_root)
{
return (0);
}
huffman_traverse(h_root, code, level);
return (1);
}
