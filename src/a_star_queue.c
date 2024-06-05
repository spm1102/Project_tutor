#include "a_star_queue.h"

queue_t *QUEUE_Create(void)
{
    queue_t *p_queue = (queue_t *)malloc(sizeof(queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void QUEUE_Put(queue_t *p_queue, int vertex, double dist, graph_t *p_graph)
{
    double heuristic_dist = p_graph->vertices[vertex].heuristic_dist;
    node_heap_t *p_node = NODE_HEAP_Create(vertex, dist, heuristic_dist);
    if (p_queue->front == NULL || dist + heuristic_dist < p_queue->front->total_dist)
    {
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    }
    else
    {
        node_heap_t *curr = p_queue->front;
        node_heap_t *pre = NULL;
        while (curr != NULL && dist + heuristic_dist >= curr->total_dist)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

node_heap_t *QUEUE_Get(queue_t *p_queue, graph_t *p_graph)
{
    if (p_queue->front == NULL)
    {
        return NULL;
    }
    int vertex = p_queue->front->vertexName;
    node_heap_t *p_node = NODE_HEAP_Create(vertex, p_queue->front->total_dist, p_graph->vertices[vertex].heuristic_dist);
    node_heap_t *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }

    NODE_HEAP_Free(temp);
    return p_node;
}

void QUEUE_Free(queue_t *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
}