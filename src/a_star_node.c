#include "a_star_node.h"

node_heap_t *NODE_HEAP_Create(int vertex, double dist, double heuristic_dist)
{
    node_heap_t *p_node_heap = (node_heap_t *)malloc(sizeof(node_heap_t));
    if (!p_node_heap)
    {
        return NULL;
    }
    p_node_heap->vertexName = vertex;
    p_node_heap->real_dist = dist;
    p_node_heap->heuristic_dist = heuristic_dist;
    p_node_heap->total_dist = dist;
    p_node_heap->next = NULL;

    return p_node_heap;
}

void NODE_HEAP_Free(node_heap_t *p_node_heap)
{
    free(p_node_heap);
}