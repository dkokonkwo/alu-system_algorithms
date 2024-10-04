#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queues.h"
#include "pathfinding.h"

/**
 * DFS - depth first search
 * @map: 2 dimensional array
 * @rows: num of rows
 * @cols: num of cols
 * @x: point x
 * @y: point y
 * @target: ending point
 * @queue: queue containining path
 * @visited: tracks visited points
 * Return: queue
 */
queue_t *DFS(char **map, int rows, int cols, int x, int y,
point_t const *target, queue_t *queue, bool **visited)
{
point_t *current;
current = malloc(sizeof(point_t));
if (!current)
return (NULL);
current->x = x;
current->y = y;
visited[y][x] = true;
printf("Checking coordinates [%d, %d]\n", x, y);
if (x == target->x && y == target->y)
{
queue_push_front(queue, current);
return (queue);
}
/* RIGHT */
if (x + 1 < cols && map[y][x + 1] == '0' &&
!visited[y][x + 1])
{
if (DFS(map, rows, cols, x + 1, y, target, queue, visited))
{
queue_push_front(queue, current);
return (queue);
}
}
/* BOTTOM */
if (y + 1 < rows && map[y + 1][x] == '0' &&
!visited[y + 1][x])
{
if (DFS(map, rows, cols, x, y + 1, target, queue, visited))
{
queue_push_front(queue, current);
return (queue);
}
}
/* LEFT */
if (x - 1 >= 0 && map[y][x - 1] == '0' &&
!visited[y][x - 1])
{
if (DFS(map, rows, cols, x - 1, y, target, queue, visited))
{
queue_push_front(queue, current);
return (queue);
}
}
/* TOP */
if (y - 1 >= 0 && map[y - 1][x] == '0' &&
!visited[y - 1][x])
{
if (DFS(map, rows, cols, x, y - 1, target, queue, visited))
{
queue_push_front(queue, current);
return (queue);
}
}
visited[y][x] = false;
free(current);
dequeue(queue);
return (NULL);
}

/**
 * backtracking_array - searches for the first path between 2 points
 * @map: pointer to a 2 dimensional array
 * @rows: num of rows
 * @cols: num of columns
 * @start: coordinates of starting point
 * @target: coordinates of target point
 * Return: queue pointing from start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
point_t const *start, point_t const *target)
{
bool **visited;
queue_t *queue, *final;
int i, j;
if (!map || rows == 0 || cols == 0 || !start || !target)
{
return (NULL);
}
visited = malloc(rows * sizeof(bool *));
if (!visited)
{
return (NULL);
}
for (i = 0; i < rows; i++)
{
visited[i] = malloc(cols * sizeof(bool));
if (!visited[i])
{
for (j = 0; j < i; j++)
{
free(visited[j]);
}
free(visited);
return (NULL);
}
}
queue = queue_create();
if (!queue)
{
for (i = 0; i < rows; i++)
{
free(visited[i]);
}
free(visited);
return (NULL);
}
for (i = 0; i < rows; i++)
{
for (j = 0; j < cols; j++)
{
visited[i][j] = false;
}
}
final = DFS(map, rows, cols, start->x, start->y, target, queue, visited);
for (i = 0; i < rows; i++)
{
free(visited[i]);}
free(visited);
return (final);
}
