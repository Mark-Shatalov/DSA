#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a two way road appears in both locations neighbour lists
void addUndirectedEdge(vector<vector<int>>& graph, int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
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

void displayAllConnections(const vector<vector<int>>& graph,
                           const vector<string>& names)
{
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
    {
        cout << names[i] << " -> ";
        for (int neighbour : graph[i])
        {
            cout << names[neighbour] << "; ";
        }
        cout << '\n';
    }
}

// check the ID before using it as a vector index
void displayLocationNeighbours(const vector<vector<int>>& graph,
                               const vector<string>& names,
                               int id)
{
    if (id < 0 || id >= static_cast<int>(graph.size()))
    {
        cout << "Invalid location ID.\n";
        return;
    }

    cout << "Selected location: " << names[id] << '\n';
    cout << "Directly reachable: ";
    for (int neighbour : graph[id])
    {
        cout << names[neighbour] << "; ";
    }
    cout << '\n';
}

int main()
{
    vector<string> names = {
        "Castle Gate", "Village", "Forest", "Old Bridge",
        "Cave", "Watch Tower", "Ruins", "Dragon Lair"
    };
    vector<vector<int>> graph(names.size());

    addUndirectedEdge(graph, 0, 1); // Gate-Village
    addUndirectedEdge(graph, 0, 2); // Gate-Forest
    addUndirectedEdge(graph, 1, 3); // Village-Bridge
    addUndirectedEdge(graph, 1, 5); // Village-Watch Tower
    addUndirectedEdge(graph, 2, 3); // Forest-Bridge
    addUndirectedEdge(graph, 2, 4); // Forest-Cave
    addUndirectedEdge(graph, 3, 6); // Bridge-Ruins
    addUndirectedEdge(graph, 5, 6); // Watch Tower-Ruins
    addUndirectedEdge(graph, 4, 6); // Cave-Ruins
    addUndirectedEdge(graph, 6, 7); // Ruins-Dragon Lair

    cout << "=== Original world ===\n";
    displayAllConnections(graph, names);

    // Part 4: query the original world before changing it
    cout << "\nLocation IDs:\n";
    for (int i = 0; i < static_cast<int>(names.size()); ++i)
    {
        cout << i << " - " << names[i] << '\n';
    }

    int id = 0;
    cout << "\nEnter location ID (0-7): ";
    if (cin >> id)
    {
        displayLocationNeighbours(graph, names, id);
    }
    else
    {
        cout << "Invalid input: please enter an integer location ID.\n";
    }

    // Part 5: open the tunnel and remove the collapsed bridge road
    addUndirectedEdge(graph, 4, 7);
    removeUndirectedEdge(graph, 1, 3);

    cout << "\n=== Modified world ===\n";
    cout << "Added: Cave <-> Dragon Lair\n";
    cout << "Removed: Village <-> Old Bridge\n\n";
    displayAllConnections(graph, names);

    cout << "\nDragon Lair after opening the tunnel:\n";
    displayLocationNeighbours(graph, names, 7);

    return 0;
}
