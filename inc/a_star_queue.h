#ifndef QUEUE_H
#define QUEUE_H

#include "a_star_node.h"

struct queue_t
{
    node_heap_t *front;
    node_heap_t *rear;
};

typedef struct queue_t queue_t;

queue_t *QUEUE_Create(void);
void QUEUE_Put(queue_t *p_queue, int vertex, double dist, graph_t *p_graph);
node_heap_t *QUEUE_Get(queue_t *p_queue, graph_t *p_graph);
void QUEUE_Free(queue_t *p_queue);

#endif