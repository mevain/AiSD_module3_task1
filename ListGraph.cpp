#include "iGraph.h"
#include "ListGraph.h"
#include <vector>
#include <cassert>

using namespace std;

ListGraph::ListGraph(int vertexCount)
{
	adjList.resize(vertexCount);
	pAdjList.resize(vertexCount);
}

ListGraph::ListGraph(const IGraph& g)
{
	int n = g.VerticesCount();
	adjList.resize(n);
	pAdjList.resize(n);

	for (int i = 0; i < n; ++i)
	{
		adjList[i] = g.GetNextVertices(i);
		pAdjList[i] = g.GetPrevVertices(i);
	}
}

void ListGraph::AddEdge(int from, int to)
{
	int verticesCount = VerticesCount();
	assert(from >= 0 && from < verticesCount);
	assert(to >= 0 && to < verticesCount);
	adjList[from].push_back(to);
	pAdjList[to].push_back(from);
}

int ListGraph::VerticesCount() const
{
	return adjList.size();
}

vector<int> ListGraph::GetNextVertices(int vertex) const
{
	assert(vertex >= 0 && vertex < adjList.size());
	return adjList[vertex];
}

vector<int> ListGraph::GetPrevVertices(int vertex) const
{
	assert(vertex >= 0 && vertex < adjList.size());
	return pAdjList[vertex];
}