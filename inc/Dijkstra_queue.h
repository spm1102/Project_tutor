#ifndef DIJKSTRA_QUEUE_H
#define DIJSKTRA_QUEUE_H

#include "Dijkstra_node.h"

struct DIJKSTRA_queue_t
{
    DIJKSTRA_node_t *front;
    DIJKSTRA_node_t *rear;
};

typedef struct DIJKSTRA_queue_t DIJKSTRA_queue_t;

static DIJKSTRA_queue_t *DIJKSTRA_QUEUE_Create(void);
static void DIJKSTRA_QUEUE_Put(DIJKSTRA_queue_t *p_queue, int vertex, int dist);
static DIJKSTRA_node_t *DIJKSTRA_QUEUE_Get(DIJKSTRA_queue_t *p_queue);
static void DIJKSTRA_QUEUE_Free(DIJKSTRA_queue_t *p_queue);
#endif