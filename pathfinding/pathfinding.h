#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"
#include <stdbool.h>
#include "graphs.h"
#include <string.h>
#include <limits.h>

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
int x;
int y;
} point_t;

/**
 * struct city_s - Structure storing city names and relative distances
 * @name: city name
 * @parent: predecessor
 * @value: relative distance to start point
 */
typedef struct city_s
{
char *name;
struct city_s *parent;
int value;
} city_t;

queue_t *backtracking_array(char **map, int rows, int cols,
point_t const *start, point_t const *target);
queue_t *DFS(char **map, int rows, int cols, int x, int y,
point_t const *target, queue_t *queue, bool **visited);
queue_t *backtracking_graph(graph_t *graph,
vertex_t const *start, vertex_t const *target);
int path_search(queue_t *path, int *visited,
vertex_t const *start, vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph,
vertex_t const *start, vertex_t const *target);
city_t **dijkstra_graph_backtrack(city_t **cities, queue_t *priority_queue,
int *visited, vertex_t const *start, vertex_t const *target);
void move_smallest_front(queue_t *priority_queue, city_t **cities);
#endif
