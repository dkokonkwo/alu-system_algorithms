#include <stdlib.h>
#include "heap.h"

/**
 * swap - swaps the data of two nodes
 * @a: first node
 * @b: second node
 */
void swap(binary_tree_node_t *a, binary_tree_node_t *b)
{
void *temp = a->data;
a->data = b->data;
b->data = temp;
}

/**
 * sift_down - restores the heap property by moving the node down
 * @heap: pointer to the heap
 * @node: node to sift down
 */
void sift_down(heap_t *heap, binary_tree_node_t *node)
{
binary_tree_node_t *smallest;
while (node->left)
{
smallest = node->left;
if (node->right && heap->data_cmp(node->right->data, node->left->data) <= 0)
smallest = node->right;

if (heap->data_cmp(smallest->data, node->data) <= 0)
{
swap(node, smallest);
node = smallest;
}
else
{
break;
}
}
}

/**
 * get_last_node - finds the last node in a complete binary heap
 * @heap: pointer to the heap
 * Return: pointer to the last node
 */
binary_tree_node_t *get_last_node(heap_t *heap)
{
binary_tree_node_t *current;
queue_t *queue = create_queue();
enqueue(queue, heap->root);
while (queue->nb_nodes)
{
current = dequeue(queue);
if (current->left)
{
enqueue(queue, current->left);
}
if (current->right)
{
enqueue(queue, current->right);
}
}

free_queue(queue);
return (current);
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: pointer to the heap
 * Return: pointer to the data stored in the root node
 */
void *heap_extract(heap_t *heap)
{
void *data;
binary_tree_node_t *last_node;
if (!heap || !heap->root)
{
return (NULL);
}
data = heap->root->data;

if (heap->size == 1)
{
free(heap->root);
heap->root = NULL;
heap->size--;
return (data);
}

last_node = get_last_node(heap);
heap->root->data = last_node->data;
if (last_node->parent->left == last_node)
{
last_node->parent->left = NULL;
}
else
{
last_node->parent->right = NULL;
}
free(last_node);
heap->size--;
sift_down(heap, heap->root);
return (data);
}
