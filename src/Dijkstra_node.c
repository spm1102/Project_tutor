#include "Dijkstra_node.h"

node_t* NODE_Create(int vertex, int dist) {
    node_t* p_node = (node_t*)malloc(sizeof(node_t));
    p_node->vertex = vertex;
    p_node->total_dist = dist;
    p_node->next = NULL;

    return p_node;
}

void NODE_Free(node_t* p_node) {
    free(p_node);
}