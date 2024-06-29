#ifndef BFS_QUEUE_H
#define BFS_QUEUE_H

#include"BFS_node.h"

typedef struct {
    node_t* front;
    node_t* rear;
} queue_t;


queue_t* QUEUE_Create(void);
void QUEUE_Put(queue_t* p_queue, int vertex);
node_t* QUEUE_Get(queue_t* p_queue);
void QUEUE_Free(queue_t* p_queue);

#endif