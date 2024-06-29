#ifndef BFS_NODE_H
#define BFS_NODE_H

#include"GRAPH_GEN.h"

struct node_t {
    int vertex;
    struct node_t* next;
};

typedef struct node_t node_t;


node_t* NODE_Create(int ver);
void NODE_Free(node_t* p_node);

#endif