#include <stdio.h>
#include "graphs.h"
#include <unistd.h>

typedef struct node_s
{
    vertex_t *vertex;
    struct node_s *next;
} node_t;

typedef struct queue_s
{
    size_t nb_nodes;
    node_t *first;
} queue_t;


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

void enqueue(queue_t *q, vertex_t *v)
{
node_t *current, *new_node;
if (!q || !v)
{
return;
}
new_node = (node_t *) malloc(sizeof(node_t));
if (!new_node)
{
return;
}
new_node->vertex = v;
new_node->next = NULL;
if (q->nb_nodes == 0)
{
q->first = new_node;
}
else
{
for (current = q->first, current->next != NULL; current = current->next)
{ ; }
current->next = new_node;
}
q->nb_nodes++;
}

vertex_t *dequeue(queue_t *q)
{
node_t *temp_node;
vertex_t *vertex;
if (!q || q->nb_nodes == 0)
{
return (NULL);
}
temp_node = q->first;
vertex = temp_node->vertex;
q->first = temp_node->next;
free(temp_node);
q->nb_nodes--;
return (vertex);
}
