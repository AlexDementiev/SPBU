#pragma once

struct Graph;

Graph *createGraph(int numberVertex);
void deleteGraph(Graph *graph);

void addEdge(Graph *graph, int firstVertex, int secondVertex, int dist);
void delteEdge(Graph *graph, int firstVertex, int secondVertex);
bool isRelated(Graph *graph, int firstVertex, int secondVertex);
int distance(Graph *graph, int firstVertex, int secondVertex);
int numberOfVertex(Graph *graph);

void setVertexColor(Graph *graph, int vertex, int color);
int getVertexColor(Graph *graph, int vertex);

void dfs(Graph *graph, int start, int color);
