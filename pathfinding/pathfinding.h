#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "queues.h"
#include <stdbool.h>
#include "graphs.h"
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_DIRECTIONS 4
#define h(x1, y1, x2, y2)  (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))

/**
 * enum direction_s - Defines directions to move
 * @RIGHT: Move to the right (east)
 * @BOTTOM: Move downwards (south)
 * @LEFT: Move to the left (west)
 * @TOP: Move upwards (north)
 * author: Frank Onyema Orji
 */
enum direction_s
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

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
vertex_t *get_min_distance(graph_t *graph, size_t *distance,
size_t *visited, size_t *index);
void insert_into_queue(graph_t *graph, queue_t *path, vertex_t **path_via,
					   vertex_t const *start, vertex_t const *target);
void recursive_dijkstra(graph_t *graph, size_t *distance, size_t *visited,
						vertex_t **path_via, vertex_t const *start,
						vertex_t const *target, size_t idx);
int init_dijkstra(graph_t *graph, size_t **distance, size_t **visited,
				  vertex_t ***path_via);
#endif
