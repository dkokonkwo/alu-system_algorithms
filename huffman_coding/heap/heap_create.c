#include "heap.h"
#include <stdio.h>

/**
 * heap_create - creates a heap structure
 * @data_cmp: pointer to comparison function
 * @Return: pointer to created heap or null pn failure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
heap_t *new_heap = (heap_t *) malloc(sizeof(heap_t));
if (!new_heap)
{
return (NULL);
}

heap->size = 0;
heap->data_cmp = data_cmp;
heap->root = NULL;

return (new_heap);
}
