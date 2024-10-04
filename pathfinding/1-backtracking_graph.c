#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pathfinding.h"

/**
 * path_search - search for first path between 2 vertices
 * @path: queue structure that stores path
 * @visited: array to tracks visited vertices
 * @start: current vertex
 * @target: target vertex
 * Return: 1 if found else 0
 */
int path_search(queue_t *path, int *visited,
vertex_t const *start, vertex_t const *target)
{
char *city;
edge_t *edge;
if (start == NULL || visited[start->index])
return (0);

printf("Checking %s\n", start->content);
visited[start->index] = 1;
if (strcmp(start->content, target->content) == 0)
{
city = strdup(start->content);
queue_push_front(path, city);
return (1);
}
for (edge = start->edges; edge; edge = edge->next)
{
if (path_search(path, visited, edge->dest, target))
{
city = strdup(start->content);
queue_push_front(path, city);
return (1);
}
}
visited[start->index] = 0;
return (0);
}

/**
 * backtracking_graph - searches for first path from starting to target
 * @graph: graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: queue or NULL
 */
queue_t *backtracking_graph(graph_t *graph,
vertex_t const *start, vertex_t const *target)
{
int success, *visited = NULL;
queue_t *path;
if (!graph || !start || !target)
return (NULL);

path = queue_create();
if (!path)
return (NULL);

visited = calloc(graph->nb_vertices, sizeof(*visited));
if (!visited)
{
queue_delete(path);
return (NULL);
}

success = path_search(path, visited, start, target);
free(visited);

if (success)
return (path);

queue_delete(path);
return (NULL);
}
