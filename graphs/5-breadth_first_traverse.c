#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * @v: vertex of the node
 */
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

/**
 * dequeue - pops first node from queue
 * @q: queue to pop from
 * Return: vertex of node
 */
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

/**
 * breadth_first_traverse - goes through a graph using bfs
 * @graph: pointer to the graph to traverse
 * @action: function to be called for each visited vertex
 * Return: biggest vertex depth
 */
size_t breadth_first_traverse(const graph_t *graph,
void (*action)(const vertex_t *v, size_t depth))
{
int *visited;
size_t max_depth = 0;
queue_t *q;
edge_t *edge;
vertex_t *vertex;
if (!graph || !graph->nb_vertices || !action)
{
return (0);
}
visited = calloc(graph->nb_vertices, sizeof(int));
if (!visited)
{
return (0);
}
q = create_queue();
enqueue(q, graph->vertices);
visited[graph->vertices->index] = 1;
action(graph->vertices, max_depth);

while (!q->nb_nodes)
{
max_depth++;
vertex = dequeue(q);
for (edge = vertex->edges; edge; edge = edge->next)
{
if (!visited[edge->dest->index])
{
enqueue(q, edge->dest);
visited[edge->dest->index] = 1;
action(edge->dest, max_depth);
}
}
}
free(visited);
free(q);

return (max_depth);
}
