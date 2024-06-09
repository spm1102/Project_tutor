#ifndef DIJKSTRA_NODE_H
#define DIJSKTRA_NODE_H

#include "GRAPH_GEN.h"

struct node_t {
    int vertex;
    int total_dist;
    struct node_t* next;
};

typedef struct node_t node_t;

node_t* NODE_Create(int vertex, int dist);
void NODE_Free(node_t* p_node);

#endif