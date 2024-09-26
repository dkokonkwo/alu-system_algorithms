#ifndef HEAP_H
#define HEAP_H

#include <unistd.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
void *data;
struct binary_tree_node_s *left;
struct binary_tree_node_s *right;
struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
size_t size;
int (*data_cmp)(void *, void *);
binary_tree_node_t *root;
} heap_t;

typedef struct node_s
{
binary_tree_node_t *b_node;
struct node_s *next;
} node_t;

typedef struct queue_s
{
size_t nb_nodes;
node_t *first;
node_t *last;
} queue_t;

queue_t *create_queue(void);
void enqueue(queue_t *q, binary_tree_node_t *node);
binary_tree_node_t *dequeue(queue_t *q);
void free_queue(queue_t *q);

heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
void sift_up(heap_t *heap, binary_tree_node_t *node);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
binary_tree_node_t *get_last_node(heap_t *heap);
void sift_down(heap_t *heap, binary_tree_node_t *node);
void swap(binary_tree_node_t *a, binary_tree_node_t *b);
void heap_delete(heap_t *heap, void (*free_data)(void *));
void recursive_free(binary_tree_node_t *node, void (*free_data)(void *));
#endif
