#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "queues.h"
#include "pathfinding.h"


/**
 * dijkstra_graph - searches for shortest path from starting to target point
 * @graph: point to graph to go through
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: queue of path
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
vertex_t const *target)
{
queue_t *path, *priority_queue;
city_t **cities;
city_t *city, *start_city;
char *name;
int *visited;
size_t i;
visited = malloc(graph->nb_vertices * sizeof(*visited));
if (!visited)
return (NULL);
cities = malloc(graph->nb_vertices * sizeof(city_t *));
if (!cities)
{
free(visited);
return (NULL); }
start_city = (city_t *)malloc(sizeof(city_t));
if (!start_city)
{
free(visited);
free(cities);
return (NULL); }
start_city->name = strdup(start->content);
start_city->parent = NULL;
start_city->value = 0;
cities[start->index] = start_city;
priority_queue = queue_create();
if (!priority_queue)
{
free(start_city->name);
free(start_city);
free(visited);
free(cities);
return (NULL); }
queue_push_front(priority_queue, (void *)start);
cities = dijkstra_graph_backtrack(cities, priority_queue,
visited, start, target);
path = queue_create();
if (!path)
{
free(visited);
for (i = 0; i < graph->nb_vertices; i++)
{
if (cities[i] != NULL)
{
free(cities[i]->name);
free(cities[i]);
}
}
free(cities);
return (NULL);
}
for (city = cities[target->index]; city != NULL; city = city->parent)
{
name = strdup(city->name);
queue_push_front(path, name);
}
free(visited);
for (i = 0; i < graph->nb_vertices; i++)
{
if (cities[i] != NULL)
{
free(cities[i]->name);
free(cities[i]);
}
}
free(cities);
return (path);
}

/**
 * dijkstra_graph_backtrack - searches for shortest path from start to target
 * @cities: predecessor array
 * @priority_queue: min heapish priority queue
 * @visited: array for tracking visited vertices
 * @start: pointer to the starting vertex
 * @target: pointer to the target vertex
 * Return: array of predecessors
 */
city_t **dijkstra_graph_backtrack(city_t **cities, queue_t *priority_queue,
int *visited, vertex_t const *start, vertex_t const *target)
{
edge_t *edge;
vertex_t *curr;
city_t *city;
curr = (vertex_t *) dequeue(priority_queue);
for (curr = (vertex_t *) dequeue(priority_queue); curr;
curr = (vertex_t *) dequeue(priority_queue))
{
printf("Checking %s, distance from %s is %d\n", curr->content,
start->content, cities[curr->index]->value);
visited[curr->index] = 1;
if (strcmp(curr->content, target->content) == 0)
break;
for (edge = curr->edges; edge; edge = edge->next)
{
if (!visited[edge->dest->index]) 
{
if (cities[edge->dest->index] && (cities[curr->index]->value + edge->weight) <
cities[edge->dest->index]->value)
{
cities[edge->dest->index]->value = cities[curr->index]->value + edge->weight;
cities[edge->dest->index]->parent = cities[curr->index];
}
if (!cities[edge->dest->index])
{
city = (city_t *)malloc(sizeof(city_t));
if (!city)
return (NULL);
city->name = strdup(edge->dest->content);
city->parent = cities[curr->index];
city->value = cities[curr->index]->value + edge->weight;
queue_push_back(priority_queue, edge->dest);
cities[neighbor->index] = city;
}
}
}
move_smallest_front(priority_queue, cities);
}
return (cities);
}

/**
 * move_smallest_front - min heapish queue for making smallest front
 * @priority_queue: priority queue to go through
 * @cities: predecessor array that tracks distances
 */
void move_smallest_front(queue_t *priority_queue, city_t **cities)
{
vertex_t *smallest, *vertex;
queue_node_t *current, *smallest_node, *temp;
if (!priority_queue->front || !priority_queue->front->next)
return;
smallest = (vertex_t *) priority_queue->front->ptr;
smallest_node = priority_queue->front;
for (current = priority_queue->front; current; current = current->next)
{
vertex = (vertex_t *)current->ptr;
if (cities[vertex->index]->value < cities[smallest->index]->value )
{
smallest = vertex;
smallest_node = current;
}
}
if (smallest_node == priority_queue->front)
return;
if (smallest_node->prev)
smallest_node->prev->next = smallest_node->next;
if (smallest_node->next)
smallest_node->next->prev = smallest_node->prev;
temp = priority_queue->front;
priority_queue->front = smallest_node;
smallest_node->next = temp;
smallest_node->prev = NULL;
if (temp)
temp->prev = smallest_node;
}
