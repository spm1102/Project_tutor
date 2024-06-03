#ifndef ENDORSED_GRAPH_H
#define ENDORSED_GRAPH_H

#include <limits.h>
#include <math.h>
#include "cell.h"

#define MAX_VERTICES 100

struct edge_t
{
    int src;
    int dest;
    int weight;
    struct edge_t *next;
};

typedef struct edge_t edge_t;

struct vertex_t
{
    int x, y;
    int visited;
    int heuristic_dist;
    int total_dist_to_src;
    int preVertex;
    edge_t *edge;
};
typedef struct vertex_t vertex_t;

struct graph_t
{
    int numVertices;
    vertex_t vertices[MAX_VERTICES];
};

typedef struct graph_t graph_t;

graph_t *GRAPH_Create(cell_t grid[COLS][ROWS]);
void GRAPH_Free(graph_t *p_graph);
void EDGE_Add(graph_t *p_graph, int src, int dest, int weight);
void EDGE_Free(edge_t *p_edge);
int distance_measure(graph_t *p_graph, int source, int dest);

#endif