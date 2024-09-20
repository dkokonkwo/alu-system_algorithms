#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * graph_add_edge - adds an edge between two vertices
 * @graph: pointer to the graph to add the edge to
 * @src: string identifying vertex to make connection from
 * @dest: string identifying vertex to connect to
 * @type: type of edge
 * Return: 1 on success, or 0 on failure
 */

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
vertex_t *current, *src_vertex, *dest_vertex;
edge_t *src_edge, *dest_edge, *current_edge;
if (!graph || !src || !dest || (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
{
return (0);
}
for (current = graph->vertices; current; current = current->next)
{
if (strcmp(current->content, src) == 0)
{
src_vertex = current;
}
if (strcmp(current->content, dest) == 0)
{
dest_vertex = current;
}
if (src_vertex && dest_vertex)
{
break;
}
}
if (!src_vertex || !dest_vertex)
{
return (0);
}
src_edge = (edge_t *) malloc(sizeof(edge_t));
if (!src_edge)
{
return (0);
}
src_vertex->nb_edges++;
src_edge->dest = dest_vertex;
src_edge->next = src_vertex->edges;
src_vertex->edges = src_edge;
if (type == BIDIRECTIONAL)
{
dest_edge = (edge_t *) malloc(sizeof(edge_t));
if (!dest_edge)
{
scr_vertex->edges = src_edge->next;
free(src_edge);
return (0);
}
dest_edge->dest = src_vertex;
dest_edge->next = dest_vertex->edges;
dest_vertex->edges = dest_edge;
dest_vertex->nb_edges++;
}
return (1);
}
