#include <memory>
#include <iostream>

class Graph
{
public:
    int V;
    int E;
    int ** Adj;
    ~Graph()
    {
        for(int i = 0; i < V; ++i)
        {
            delete Adj[i];
        }
        delete Adj;
    }
};

std::unique_ptr<Graph> adjMatrixOfGraph()
{
    std::unique_ptr<Graph> G = std::make_unique<Graph>();
    std::cout << "Number of vertices: ";
    std::cin >> G->V;
    std::cout << "Number of edges: ";
    std::cin >> G->E;
    G->Adj = new int*[G->V];
    for(int i = 0; i < G->E; ++i)
    {
        G->Adj[i] = new int[G->V];
    }

    for(int i = 0; i < G->V; ++i)
    {
        for(int j = 0; j < G->V; ++j)
        {
            G->Adj[i][j] = 0;
        }
    }
    for(int e = 0; e < G->E; ++e)
    {
        int u{};
        int v{};
        std::cout << "Reading edge between: \n";
        std::cin >> u >> v;
        G->Adj[u][v] = 1;
    }
    return G;
}