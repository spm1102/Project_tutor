#ifndef BFS_QUEUE_H
#define BFS_QUEUE_H

#include"BFS_node.h"

typedef struct {
    node_t* front;
    node_t* rear;
} BFS_queue_t;


BFS_queue_t* BFS_QUEUE_Create(void);
void BFS_QUEUE_Put(BFS_queue_t* p_queue, int vertex);
node_t* BFS_QUEUE_Get(BFS_queue_t* p_queue);
void BFS_QUEUE_Free(BFS_queue_t* p_queue);

#endif