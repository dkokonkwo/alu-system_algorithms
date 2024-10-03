#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queues.h"
#include "pathfinding.h"


queue_t *DFS(char **map, int rows, int cols, point_t const *start, point_t const *target, queue_t *queue, char **visited)
{
    point_t *new_start;
    queue_node_t *node;
    if (!queue->front)
    {
        node = queue_push_front(queue, (void *)start);
    }
    else
    {
        node = queue_push_back(queue, (void *)start);
    }
    visited[start->x][start->y] = true;
    printf("checking coordinated [%d, %d]\n", start->x, start->y);
    if (start->x == target->x && start->y == target->y)
    {
        return (queue);
    }
    new_start = malloc(sizeof(point_t));
    if (!new_start)
    {
        return (NULL);
    }
    if (start->y + 1 < cols && map[start->x][start->y + 1] == '0' && !visited[start->x][start->y + 1])
    {
        new_start->x = start->x;
        new_start->y = start->y + 1;
        if (DFS(map, rows, cols, new_start, target, queue, visited))
        {
            return (queue);
        }
    }

    if (start->x + 1 < rows && map[start->x + 1][start->y] == '0' && !visited[start->x + 1][start->y])
    {
        new_start->x = start->x + 1;
        new_start->y = start->y;
        if (DFS(map, rows, cols, new_start, target, queue, visited))
        {
            return (queue);
        }
    }
    if (start->y - 1 >= 0 && map[start->x][start->y - 1] == '0' && !visited[start->x][start->y - 1])
    {
        new_start->x = start->x;
        new_start->y = start->y - 1;
        if (DFS(map, rows, cols, new_start, target, queue, visited))
        {
            return (queue);
        }
    }
    if (start->x - 1 >= 0 && map[start->x - 1][start->y] == '0' && !visited[start->x - 1][start->y])
    {
        new_start->x = start->x - 1;
        new_start->y = start->y;
        if (DFS(map, rows, cols, new_start, target, queue, visited))
        {
            return (queue);
        }
    }
    visited[start->x][start->y] = false;
    dequeue(queue);
    free(new_start);
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
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
    bool visited[rows][cols];
    queue_t *queue;
    int i, j;
    if (!map || rows == 0 || cols == 0 || !start || !target)
    {
        return (NULL);
    }
    queue = queue_create();
    if (!queue)
    {
        return NULL;
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            visited[i][j] = false;
        }
    }
    queue = DFS(map, rows, cols, start, target, queue, visited);
    return (queue);


