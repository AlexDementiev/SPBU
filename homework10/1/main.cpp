#include <iostream>
#include <fstream>
#include "tile.h"
#include "avl.h"

using namespace std;

struct Map
{
    int height;
    int width;
    Tile ***array;
};

Map *inputMap(istream &stream)
{
    Map *map = new Map;
    stream >> map->height >> map->width;
    map->array = new Tile**[map->height];
    for (int i = 0; i < map->height; i++)
    {
        map->array[i] = new Tile*[map->width];
        char current = '\0';
        for (int j = 0; j < map->width; j++)
        {
            stream >> current;
            map->array[i][j] = newTile(current == '0', i, j);
        }
    }
    return map;
}

void printMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
            if (isInPath(map->array[i][j]))
                cout << "*";
            else if (isFree(map->array[i][j]))
                cout << "0";
            else
                cout << "1";
        cout << endl;
    }
}

void deleteMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
            deleteTile(map->array[i][j]);
        delete[] map->array[i];
    }
    delete[] map->array;
    delete map;
}

int euristic(int x, int y, int finishX, int finishY)
{
    return abs(finishX - x) + abs(finishY - y);
}

void reflect(Tile *reflected, Tile *current, AVLTree *queue, int euristicValue)
{
    if (contains(queue, reflected))
        remove(queue, reflected);
    setDistance(reflected, distance(current) + 1);
    setPrevios(reflected, current);
    setPriority(reflected, distance(reflected) + euristicValue);
    add(queue, reflected);
}

void AStar(Map *map, int startX, int startY, int finishX, int finishY)
{
    if (!isFree(map->array[startX][startY]))
        return;

    AVLTree *priorityQueue = createTree();

    setDistance(map->array[startX][startY], 0);
    setPriority(map->array[startX][startY], euristic(startX, startY, finishX, finishY));

    add(priorityQueue, map->array[startX][startY]);

    while(!isEmpty(priorityQueue) && !isVisited(map->array[finishX][finishY]))
    {
        Tile *current = getMin(priorityQueue);
        setVisited(current);

        int x = tileX(current);
        int y = tileY(current);

        if (x - 1 >= 0 && isFree(map->array[x - 1][y]) && distance(map->array[x - 1][y]) > distance(current) + 1)
            reflect(map->array[x - 1][y], current, priorityQueue, euristic(x - 1, y, finishX, finishY));

        if (y - 1 >= 0 && isFree(map->array[x][y - 1]) && distance(map->array[x][y - 1]) > distance(current) + 1)
            reflect(map->array[x][y - 1], current, priorityQueue, euristic(x, y - 1, finishX, finishY));

        if (x + 1 < map->height && isFree(map->array[x + 1][y]) && distance(map->array[x + 1][y]) > distance(current) + 1)
            reflect(map->array[x + 1][y], current, priorityQueue, euristic(x + 1, y, finishX, finishY));

        if (y + 1 < map->width && isFree(map->array[x][y + 1]) && distance(map->array[x][y + 1]) > distance(current) + 1)
            reflect(map->array[x][y + 1], current, priorityQueue, euristic(x, y + 1, finishX, finishY));

    }

    deleteTree(priorityQueue);

    if (isVisited(map->array[finishX][finishY]))
    {
        Tile *current = map->array[finishX][finishY];
        setInPath(current);
        while (current != map->array[startX][startY])
        {
            current = previous(current);
            setInPath(current);
        }
    }
}


int main()
{
    ifstream inputFile;
    inputFile.open("map.txt");
    if (!inputFile.is_open())
    {
        cout << "File is not found" << endl;
        return 0;
    }

    Map *map = inputMap(inputFile);
    inputFile.close();

    int startX = 0;
    int startY = 0;
    int finishX = 0;
    int finishY = 0;
    cout << "Enter row (X) and column (Y) of start: (X <= " << map->height - 1 << "), (Y <= " << map->width - 1 << ")" << endl;
    cin >> startX >> startY;
    cout << "Enter row (X) and column (Y) of finish: (X <= " << map->height - 1 << "), (Y <= " << map->width - 1 << ")" << endl;
    cin >> finishX >> finishY;

    AStar(map, startX, startY, finishX, finishY);

    if (isVisited(map->array[finishX][finishY]))
    {
        cout << "Path is found. Length: " << distance(map->array[finishX][finishY]) << endl;
        printMap(map);
    }
    else
    {
        cout << "Path is not found" << endl;
    }


    deleteMap(map);
    return 0;
}
