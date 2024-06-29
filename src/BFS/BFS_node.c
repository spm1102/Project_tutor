#include "BFS_node.h"

node_t *NODE_Create(int ver)
{
    node_t *p_node = (node_t *)malloc(sizeof(node_t));
    p_node->vertex = ver;
    p_node->next = NULL;
    return p_node;
}

void NODE_Free(node_t *p_node)
{
    free(p_node);
}