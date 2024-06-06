#include "a_star.h"

void a_star_queue(graph_t *p_graph, int startVertex, int destination, void (*GUI_displaypPath)(graph_t *p_graph))
{
    queue_t *p_queue = NULL;
    p_queue = QUEUE_Create();
    p_graph->vertices[startVertex].total_dist = 0;
    QUEUE_Put(p_queue, startVertex, 0, p_graph);
    while (p_queue->front != NULL)
    {
        node_heap_t *minNode = QUEUE_Get(p_queue, p_graph);
        int currentVertex = minNode->vertexName;
        NODE_HEAP_Free(minNode);

        if (currentVertex == destination)
        {
            break;
        }

        p_graph->vertices[currentVertex].visited = 1;
        GUI_displaypPath(p_graph);

        edge_t *temp = p_graph->vertices[currentVertex].edge;
        while (temp != NULL)
        {
            int nextVertex = temp->dest;
            int weight = temp->weight;

            if (!p_graph->vertices[nextVertex].visited)
            {
                double newDist = p_graph->vertices[currentVertex].total_dist + weight;
                double heuristic_of_nextVertex = p_graph->vertices[nextVertex].heuristic_dist;
                if (newDist + heuristic_of_nextVertex < p_graph->vertices[nextVertex].total_dist + heuristic_of_nextVertex)
                {
                    p_graph->vertices[nextVertex].total_dist = newDist;
                    p_graph->vertices[nextVertex].preVertex = currentVertex;
                    QUEUE_Put(p_queue, nextVertex, newDist + heuristic_of_nextVertex, p_graph);
                }
            }
            temp = temp->next;
        }
    }
    QUEUE_Free(p_queue);
}