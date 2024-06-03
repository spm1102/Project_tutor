#ifndef NODE_HEAP_H
#define NODE_HEAP_H

#include "GRAPH_GEN.h"

struct node_heap_t
{
    int vertexName;
    int real_dist;
    int total_dist_to_src;
    struct node_heap_t *next;
};

typedef struct node_heap_t node_heap_t;

node_heap_t *NODE_HEAP_Create(int vertex, int dist, int heuristic_dist);
void NODE_HEAP_Free(node_heap_t *p_node_heap);

#endif