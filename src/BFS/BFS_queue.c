#include "BFS_queue.h"

queue_t* QUEUE_Create(void){
    queue_t* p_queue = (queue_t*)malloc(sizeof(queue_t));
    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void QUEUE_Put(queue_t* p_queue, int vertex){
    node_t* p_node = NODE_Create(vertex);
    if(p_queue->rear == NULL){
        p_queue->front = p_node;
        p_queue->rear = p_node;
    }
    else{
        p_queue->rear->next = p_node;
        p_queue->rear = p_node;
    }
}


node_t* QUEUE_Get(queue_t* p_queue){
    if(p_queue->front == NULL){
        return NULL;
    }
    node_t* p_node = NODE_Create(p_queue->front->vertex);
    node_t* temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if(p_queue->front == NULL){
        p_queue->rear = NULL;
    }

    NODE_Free(temp);
    return p_node;
}

void QUEUE_Free(queue_t* p_queue){
    p_queue->front = NULL;
    p_queue->rear =NULL;
    free(p_queue);
}