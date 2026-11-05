#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void addUndirectedEdge(vector<vector<int>>& graph, int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void displayAllConnections(const vector<vector<int>>& graph,
                           const vector<string>& names)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << names[i] << " -> ";

        for (int neighbour : graph[i])
        {
            cout << names[neighbour] << " ";
        }

        cout << "\n";
    }
}

void displayLocationNeighbours(const vector<vector<int>>& graph,
                               const vector<string>& names,
                               int id)
{
    if (id < 0 || id >= graph.size())
    {
        cout << "Invalid location ID.\n";
        return;
    }

    cout << "Selected location: " << names[id] << "\n";
    cout << "Directly reachable: ";

    for (int neighbour : graph[id])
    {
        cout << names[neighbour] << " ";
    }

    cout << "\n";
}

void removeUndirectedEdge(vector<vector<int>>& graph, int a, int b)
{
    graph[a].erase(
        remove(graph[a].begin(), graph[a].end(), b),
        graph[a].end()
    );

    graph[b].erase(
        remove(graph[b].begin(), graph[b].end(), a),
        graph[b].end()
    );
}

int main()
{
    vector<string> names =
    {
        "Castle Gate",
        "Village",
        "Forest",
        "Old Bridge",
        "Cave",
        "Watch Tower",
        "Ruins",
        "Dragon Lair"
    };

    vector<vector<int>> graph(8);

    // Part 3
    addUndirectedEdge(graph, 0, 1);
    addUndirectedEdge(graph, 0, 2);
    addUndirectedEdge(graph, 1, 3);
    addUndirectedEdge(graph, 1, 5);

    addUndirectedEdge(graph, 2, 3);
    addUndirectedEdge(graph, 2, 4);
    addUndirectedEdge(graph, 3, 6);
    addUndirectedEdge(graph, 5, 6);
    addUndirectedEdge(graph, 4, 6);
    addUndirectedEdge(graph, 6, 7);

    cout << "All connections:\n";
    displayAllConnections(graph, names);
    cout << "\n";

    // The outer loop goes through every location in the graph.
    // The inner loop prints all the neighbours of that location.
    // It uses graph[i] because graph[i] is the list of neighbours for location i.

    // Part 4
    int id;

    cout << "Enter location ID (0-7): ";
    cin >> id;

    displayLocationNeighbours(graph, names, id);
    cout << "\n";

    // Dragon Lair only has one neighbour because the only road to it is from Ruins.

    // Part 5
    addUndirectedEdge(graph, 4, 7);
    removeUndirectedEdge(graph, 1, 3);

    cout << "After secret tunnel and bridge collapse:\n";
    displayAllConnections(graph, names);

    // The two lists that changed are Village and Old Bridge.
    // Village no longer has Old Bridge and Old Bridge no longer has Village.
    // An undirected edge is stored in both lists, so we have to remove it from both.
    // If we only removed one side, the road would still work one way.

    return 0;
}
