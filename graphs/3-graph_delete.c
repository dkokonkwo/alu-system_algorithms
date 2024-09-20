#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * graph_delete - completely deletes a graph
 */
void graph_delete(graph_t *graph)
{
vertex_t *vertex;
edge_t *edge;
if (!graph)
{
return;
}
for (vertex = graph->vertices; vertex; vertex = vertex->next)
{
for (edge = vertex->edges; edge; edge = edge->next)
{
free(edge);
}
free(vertex);
}
}
