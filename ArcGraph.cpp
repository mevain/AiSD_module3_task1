#include "iGraph.h"
#include "ArcGraph.h"
#include <vector>

using namespace std;

ArcGraph::ArcGraph(int verticesCount)
{
    adjList.reserve(0);
}

ArcGraph::ArcGraph(const IGraph& graph)
{
    int n = graph.VerticesCount();
    adjList.reserve(n);

    for (int i = 0; i < n; ++i) 
    {
        vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j)
        {
            adjList.emplace_back(i, nextVertices[j]);
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    adjList.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const
{
    int ans = -1;
    for (int i = 0; i < adjList.size(); ++i)
    {
        ans = max(ans, max(adjList[i].first, adjList[i].second));
    }
    ++ans;
    return ans;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    vector<int> nextVertices;
    for (int i = 0; i < adjList.size(); ++i)
    {
        if (vertex == adjList[i].first)
        {
            nextVertices.push_back(adjList[i].second);
        }
    }
    return nextVertices;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    vector<int> prevVertices;
    for (int i = 0; i < adjList.size(); ++i)
    {
        if (vertex == adjList[i].second) {
            prevVertices.push_back(adjList[i].first);
        }
    }
    return prevVertices;
}