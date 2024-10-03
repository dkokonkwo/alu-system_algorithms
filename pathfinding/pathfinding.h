#ifndef PATHFINDING_H
#define PATHFINDING_H

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

queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);
queue_t *DFS(char **map, int rows, int cols, point_t const *start, point_t const *target, queue_t *queue, bool *visited);
#endif
