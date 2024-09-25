#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * create_queue - create a queue data structure
 * Return: created empty queue
 */
queue_t *create_queue(void)
{
queue_t *queue = (queue_t *) malloc(sizeof(queue_t));
if (!queue)
{
return (NULL);
}

queue->nb_nodes = 0;
queue->first = NULL;

return (queue);
}

/**
 * enqueue - add node to queue
 * @q: queue to add node to
 * @v: node
 */
void enqueue(queue_t *q, binary_tree_node_t *node)
{
node_t *current, *new_node;
if (!q || !node)
{
return;
}

new_node = (node_t *) malloc(sizeof(node_t));
if (!new_node)
{
return;
}
new_node->b_node = node;
new_node->next = NULL;
if (q->nb_nodes == 0)
{
q->first = new_node;
}
else
{
for (current = q->first; current->next; current = current->next)
{ ; }
current->next = new_node;
}
q->nb_nodes++;
}

/**
 * dequeue - pops first node from queue
 * @q: queue to pop from
 * Return: node
 */
binary_tree_node_t *dequeue(queue_t *q)
{
node_t *temp_node;
binary_tree_node_t *node;
if (!q || q->nb_nodes == 0)
{
return (NULL);
}
temp_node = q->first;
node = temp_node->b_node;
q->first = temp_node->next;
free(temp_node);
q->nb_nodes--;
return (node);
}

/**
 * sift_up - moves smallest nodes up
 * @heap - min binary heap
 * @node - added node
 */
void sift_up(heap_t *heap, binary_tree_node_t *node)
{
void *temp;
while (node->parent && heap->data_cmp(node->data, node->parent->data) < 0)
{
temp = node->data;
node->data = node->parent->data;
node->parent->data = temp;

node = node->parent;
}
}

/**
 * heap_insert - inserts a value to a min binary heap
 * @heap: pointer to the heap
 * @data: sata to store in the new node
 * Return: pointer to created node or NULL on failure
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
binary_tree_node_t *new_node;
binary_tree_node_t *current;
queue_t *queue;
if (!heap || !data)
{
return (NULL);
}

new_node = binary_tree_node(NULL, data);
if (!heap->root)
{
heap->root = new_node;
}
else
{
queue = create_queue();
enqueue(queue, heap->root);
while ((current = dequeue(queue)))
{
if (!current->left)
{
current->left = new_node;
new_node->parent = current;
break;
}
else
{
enqueue(queue, current->left);
}

if (!current->right)
{
current->right = new_node;
new_node->parent = current;
break;
}
else
{
enqueue(queue, current->right);
}
}

free(queue);
}

heap->size++;
return(new_node);
}
