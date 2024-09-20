#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: graph to add vertext to
 * @str: vertex content
 * Return: vertex or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
vertex_t *current, *new_vertex;
if (graph == NULL || str == NULL)
{
return (NULL);
}
for (current = graph->vertices; current; current = current->next)
{
if (strcmp(current->content, str) == 0)
{
return (NULL);
}
}
new_vertex = (vertex_t *)malloc(sizeof(vertex_t));
if (new_vertex == NULL)
{
return (NULL);
}
new_vertex->content = strdup(str);
if (new_vertex->content == NULL)
{
free(new_vertex);
return (NULL);
}
new_vertex->index = graph->nb_vertices++;
new_vertex->nb_edges = 0;
new_vertex->edges = NULL;
new_vertex->next = NULL;
if (graph->vertices == NULL)
{
graph->vertices = new_vertex;
}
else
{
for (current = graph->vertices; current->next; current = current->next)
{
; }
current->next = new_vertex;
}
return (new_vertex);
}
