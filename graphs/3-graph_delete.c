#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * graph_delete - completely deletes a graph
 * @graph: pointer to the graph to delete
 */
void graph_delete(graph_t *graph)
{
vertex_t *vertex, *temp_vertex;
edge_t *edge, *temp_edge;

if (!graph)
{
return;
}
vertex = graph->vertices;
while (vertex)
{
edge = vertex->edges;
while (edge)
{
temp_edge = edge->next;
free(edge);
edge = temp_edge;
}

free(vertex->content);

temp_vertex = vertex->next;
free(vertex);
vertex = temp_vertex;
}

free(graph);
}
