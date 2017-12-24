#include <iostream>
#include <fstream>

#include "graph.h"

using namespace std;

Graph *inputGraph(istream &stream)
{
    int numberOfVertex;
    int numberOfEdges;
    stream >> numberOfVertex >> numberOfEdges;

    Graph *graph = createGraph(numberOfVertex);
    for (int i = 0; i < numberOfEdges; i++)
    {
        int firstVertex;
        int secondVertex;
        int distance;
        stream >> firstVertex >> secondVertex >> distance;
        addEdge(graph, firstVertex, secondVertex, distance);
    }

    return graph;
}

void printTheWay(int *previous, int vertex)
{
    while (previous[vertex] != -1)
    {
        cout << " <- " << previous[vertex];
        vertex = previous[vertex];
    }
}

void dijkstra(Graph *graph, int start)
{
    int const infinity = 10000000;
    int const size = numberOfVertex(graph);

    int *result = new int[size];
    int *previous = new int[size];
    bool *visited = new bool[size];

    for (int i = 0; i < size; i++)
    {
        result[i] = infinity;
        previous[i] = -1;
        visited[i] = false;
    }
    
    cout << "Capture order: ";
    result[start] = 0;
    int current = 1;
    while (!visited[current])
    {
        visited[current] = true;
        cout << current << " ";
        for (int i = 1; i < size; i++)
            if (!visited[i] && isRelated(graph, current, i) && result[current] + distance(graph, current, i) < result[i])
            {
                previous[i] = current;
                result[i] = result[current] + distance(graph, current, i);
            }

        int minDistance = infinity;
        for (int i = 0; i < size; i++)
            if (!visited[i] && result[i] < minDistance)
            {
                minDistance = result[i];
                current = i;
            }
    }

    cout << endl;
    cout << "Paths: \n";
    for (int i = 1; i < size; i++)
        if (visited[i])
        {
            cout << i;
            printTheWay(previous, i);
            cout << " (distance: " << result[i] << ")" << endl;
        }

    delete[] result;
    delete[] previous;
    delete[] visited;
}

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");

    if (!inputFile.is_open())
    {
        cout << "File not found";
        return 0;
    }

    Graph *graph = inputGraph(inputFile);
    inputFile.close();

    dijkstra(graph, 1);
    deleteGraph(graph);
    return 0;
}
