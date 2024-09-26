#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"

/**
 * symbol_create - creates a symbol_t data structure
 * @data: data to be stored in structure
 * @freq: associated frequency
 * Return: pointer to created symbol or NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{
symbol_t *symbol;
if (!data || !freq)
{
return (NULL);
}
symbol = (symbol_t *)malloc(sizeof(symbol_t));
if (!symbol)
{
return (NULL);
}

symbol->data = data;
symbol->freq = freq;

return (symbol);
}
