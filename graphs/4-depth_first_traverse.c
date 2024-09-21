#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * dfs - depth first search
 * @vertex: current vertex
 * @action: pointer to function to perform on vertex
 * @visited: array keeping track of visited vertices
 * @depth: current depth relative to last vertex
 */
size_t depth_first_search(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
int *visited, size_t depth)
{
edge_t *edge;
size_t max_depth = depth, child_depth;
if (visited[vertex->index] == 1)
{
return (max_depth);
}
visited[vertex->index] = 1;
action(vertex, depth);
if (vertex->nb_edges == 0)
{
return (max_depth);
}
for (edge = vertex->edges; edge; edge = edge->next)
{
if (!visited[edge->dest->index])
{
child_depth = depth_first_search(edge->dest, action, visited, depth + 1);
if (child_depth > max_depth)
{
max_depth = child_depth;
}
}
}
return (max_depth);
}


/**
 * depth_first_traverse - goes through a graph using df algo
 * @graph: pointer to graph to traverse
 * @action: pointer to function to be called at each visited vertex
 * Return: biggest vertex depth,or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
void (*action)(const vertex_t *v, size_t depth))
{
int *visited;
size_t max_depth = 0;
if (!graph || !graph->nb_vertices || !action) 
{
return (0);
}
visited = calloc(graph->nb_vertices, sizeof(int));
if (!visited)
{
return (0);
}
max_depth = depth_first_search(graph->vertices, action, visited, 0);

free(visited);

return (max_depth);
}
