#include <iostream>
using namespace std;

class Graph
{
    int adjacencyMatrix[10][10];
    int visited[10];
    int vertices, edges;

public:

    void CreateGraph()
    {
        int source, destination;

        cout << "Enter Number of Vertices: ";
        cin >> vertices;

        // Initialize adjacency matrix
        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }

        cout << "Enter Number of Edges: ";
        cin >> edges;

        // Insert edges
        for (int k = 1; k <= edges; k++)
        {
            cout << "Enter Source and Destination: ";
            cin >> source >> destination;

            adjacencyMatrix[source][destination] = 1;
            adjacencyMatrix[destination][source] = 1;
        }
    }

    void DisplayGraph()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 1; i <= vertices; i++)
        {
            for (int j = 1; j <= vertices; j++)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex)
    {
        visited[vertex] = 1;

        cout << vertex << " ";

        for (int i = 1; i <= vertices; i++)
        {
            if (adjacencyMatrix[vertex][i] == 1 && visited[i] == 0)
            {
                DFS(i);
            }
        }
    }

    void InitializeVisited()
    {
        for (int i = 1; i <= vertices; i++)
        {
            visited[i] = 0;
        }
    }
};

int main()
{
    Graph graph;
    int startVertex;

    graph.CreateGraph();
    graph.DisplayGraph();
    graph.InitializeVisited();

    cout << "\nEnter Starting Vertex: ";
    cin >> startVertex;

    cout << "DFS Traversal: ";
    graph.DFS(startVertex);

    return 0;
}
