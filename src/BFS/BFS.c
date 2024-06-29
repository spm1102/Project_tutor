#include "BFS.h"

void BFS(graph_t* p_graph, cell_t** grid,int startVertex, int destination, void (*GUI_displayPath)(graph_t* p_graph, cell_t **grid)) {
    queue_t* p_queue = QUEUE_Create();
    QUEUE_Put(p_queue, startVertex);
    while(p_queue->front != NULL){
        node_t* minNode = QUEUE_Get(p_queue);
        int currentVertex = minNode->vertex;
        NODE_Free(minNode);
        if(currentVertex == destination){
            break;
        }
        
        if(p_graph->vertices[currentVertex].visited) {
            continue;
        }
        p_graph->vertices[currentVertex].visited = 1;
        GUI_displayPath(p_graph, grid);

        edge_t* temp = p_graph->vertices[currentVertex].edge;
        while(temp != NULL){
            int nextVertex = temp->dest;
            if(!p_graph->vertices[nextVertex].visited){
                p_graph->vertices[nextVertex].preVertex = currentVertex;
                QUEUE_Put(p_queue, nextVertex);
            }
            temp = temp->next;
        }
    }
    QUEUE_Free(p_queue);
}