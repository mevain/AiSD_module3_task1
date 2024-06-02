#include "SetGraph.h"
#include <cassert>

using namespace std;

SetGraph::SetGraph(int verticesCount)
{
    adjSet.resize(verticesCount);
    prevSet.resize(verticesCount);
}

SetGraph::SetGraph(const IGraph& graph)
{
    int verticesCount = graph.VerticesCount();
    adjSet.resize(verticesCount);
    prevSet.resize(verticesCount);
    for (int i = 0; i < verticesCount; ++i)
    {
        vector<int> nextVertices = graph.GetNextVertices(i);
        for (int j = 0; j < nextVertices.size(); ++j)
        {
            adjSet[i].insert(nextVertices[j]);
            prevSet[j].insert(i);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < adjSet.size());
    assert(0 <= to && to < adjSet.size());
    int verticesCount = VerticesCount();
    adjSet[from].insert(to);
    prevSet[to].insert(from);
}

int SetGraph::VerticesCount() const
{
    return adjSet.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const
{
    int n = VerticesCount();
    assert(0 <= vertex && vertex < n);
    vector<int> nextVertices;
    for (auto vertex: adjSet[vertex])
    {
        nextVertices.push_back(vertex);
    }
    return nextVertices;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    int n = VerticesCount();
    assert(0 <= vertex && vertex < n);
    vector<int> prevVertices;
    for (auto vertex: prevSet[vertex])
    {
        prevVertices.push_back(vertex);
    }
    return prevVertices;
}
