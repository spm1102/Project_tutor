#include "Dijkstra_queue.h"
queue_t *QUEUE_Create(void)
{
    queue_t *p_queue = (queue_t *)malloc(sizeof(queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void QUEUE_Put(queue_t *p_queue, int vertex, int dist)
{
    node_t *p_node = NODE_Create(vertex, dist);
    if (p_queue->front == NULL || dist < p_queue->front->total_dist)
    {
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    }
    else
    {
        node_t *curr = p_queue->front;
        node_t *pre = NULL;
        while (curr != NULL && dist >= curr->total_dist)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

node_t *QUEUE_Get(queue_t *p_queue)
{
    if (p_queue->front == NULL)
    {
        return NULL;
    }
    node_t *p_node = NODE_Create(p_queue->front->vertex, p_queue->front->total_dist);
    node_t *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    NODE_Free(temp);
    return p_node;
}

void QUEUE_Free(queue_t *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
}