#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * graph_create - allocates memory to store structure
 * Return: pointer or NULL on failure
 */

graph_t *graph_create(void)
{
graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
if (graph == NULL)
{
printf("Memory allocation failed\n");
return NULL;
}

graph->nb_vertices = 0;
graph->vertices = NULL;

return (graph);
}
