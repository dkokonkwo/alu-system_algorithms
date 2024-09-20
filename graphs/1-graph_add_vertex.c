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
vertex_t *current = graph->vertices;
vertex_t *new_vertex = (vertex_t *) malloc(sizeof(vertex_t));
if (graph == NULL || str == NULL)
{
return (NULL);
}

while (current != NULL)
{
if (strcmp(current->content, str) == 0)
{
return (NULL);
}
current = current->next;
}

if (new_vertex == NULL)
{
printf("Error creating new vertex.\n");
return (NULL);
}

new_vertex->content = strdup(str);
if (new_vertex->content == NULL)
{
printf("Adding vertex content failed.\n");
free(new_vertex);
return (NULL);
}

new_vertex->index = graph->nb_vertices;
new_vertex->nb_edges = 0;
new_vertex->edges = NULL;
new_vertex->next = NULL;

graph->nb_vertices++;

return (new_vertex);
}
