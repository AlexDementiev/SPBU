#include <iostream>
#include <fstream>
#include "tile.h"
#include "avl.h"

using namespace std;

struct Map
{
    int height;
    int width;
    Tile ***set;
};

Map *inputMap(istream &stream)
{
    Map *map = new Map;
    stream >> map->height >> map->width;
    map->set = new Tile**[map->height];
    for (int i = 0; i < map->height; i++)
    {
        map->set[i] = new Tile*[map->width];
        char symbol = '\0';
        for (int j = 0; j < map->width; j++)
        {
            stream >> symbol;
            map->set[i][j] = createTile(symbol == '0', i, j);
        }
    }
    return map;
}

void printMap(Map *map)
{
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
            if (isInPath(map->set[i][j]))
                cout << "*";
            else if (isFree(map->set[i][j]))
                cout << " ";
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
            deleteTile(map->set[i][j]);
        delete[] map->set[i];
    }
    delete[] map->set;
    delete map;
}

int euristic(int x, int y, int finishX, int finishY)
{
    return abs(finishX - x) + abs(finishY - y);
}

void reaction(Tile *reflected, Tile *current, AVLTree *queue, int euristicValue)
{
    if (contains(queue, reflected))
        removeTile(queue, reflected);
    setDistance(reflected, distance(current) + 1);
    setPrevious(reflected, current);
    setPriority(reflected, distance(reflected) + euristicValue);
    add(queue, reflected);
}

void AStar(Map *map, int startX, int startY, int finishX, int finishY)
{
    if (!isFree(map->set[startX][startY]))
        return;

    AVLTree *priorityQueue = createTree();

    setDistance(map->set[startX][startY], 0);
    setPriority(map->set[startX][startY], euristic(startX, startY, finishX, finishY));

    add(priorityQueue, map->set[startX][startY]);

    while (!isEmpty(priorityQueue) && !isVisited(map->set[finishX][finishY]))
    {
        Tile *current = getMin(priorityQueue);
        setVisited(current);

        int x = getX(current);
        int y = getY(current);

        if (x - 1 >= 0 && isFree(map->set[x - 1][y]) && distance(map->set[x - 1][y]) > distance(current) + 1)
            reaction(map->set[x - 1][y], current, priorityQueue, euristic(x - 1, y, finishX, finishY));

        if (y - 1 >= 0 && isFree(map->set[x][y - 1]) && distance(map->set[x][y - 1]) > distance(current) + 1)
            reaction(map->set[x][y - 1], current, priorityQueue, euristic(x, y - 1, finishX, finishY));

        if (x + 1 < map->height && isFree(map->set[x + 1][y]) && distance(map->set[x + 1][y]) > distance(current) + 1)
            reaction(map->set[x + 1][y], current, priorityQueue, euristic(x + 1, y, finishX, finishY));

        if (y + 1 < map->width && isFree(map->set[x][y + 1]) && distance(map->set[x][y + 1]) > distance(current) + 1)
            reaction(map->set[x][y + 1], current, priorityQueue, euristic(x, y + 1, finishX, finishY));
    }

    clearTree(priorityQueue);

    if (isVisited(map->set[finishX][finishY]))
    {
        Tile *current = map->set[finishX][finishY];
        setInPath(current);
        while (current != map->set[startX][startY])
        {
            current = previous(current);
            setInPath(current);
        }
    }
}

int main()
{
    ifstream input;
    input.open("map.txt");
    if (!input.is_open())
    {
        cout << "File not found.";
        return 0;
    }

    Map *map = inputMap(input);
    input.close();

    int startX = 0;
    int startY = 0;
    int finishX = 0;
    int finishY = 0;

    cout << "Enter row (X) and column (Y) of start: (X <= " << map->height - 1 << "), ( Y <= " << map->width - 1 << ")\n";
    cin >> startX >> startY;

    cout << "Enter row (X) and column (Y) of finish: (X <= " << map->height - 1 << "), ( Y <= " << map->width - 1 << ")\n";
    cin >> finishX >> finishY;

    AStar(map, startX, startY, finishX, finishY);

    if (isVisited(map->set[finishX][finishY]))
    {
        cout << "Path is found. Length: " << distance(map->set[finishX][finishY]) << endl;
        printMap(map);
    }
    else
        cout << "Path nit found.\n";

    deleteMap(map);
    return 0;
}
