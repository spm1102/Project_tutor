#ifndef DIJKSTRA_QUEUE_H
#define DIJSKTRA_QUEUE_H

#include "Dijkstra_node.h"

struct queue_t
{
    node_t *front;
    node_t *rear;
};

typedef struct queue_t queue_t;

static queue_t *QUEUE_Create(void);
static void QUEUE_Put(queue_t *p_queue, int vertex, int dist);
static node_t *QUEUE_Get(queue_t *p_queue);
static void QUEUE_Free(queue_t *p_queue);
#endif