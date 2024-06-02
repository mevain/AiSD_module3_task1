#include "iGraph.h"
#include "MatrixGraph.h"
#include <vector>
#include <cassert>

using namespace std;

MatrixGraph::MatrixGraph(int verticesCount)
{
	adjMatrix.resize(verticesCount, vector<bool>(verticesCount, false));
}

MatrixGraph::MatrixGraph(const IGraph & g)
{
	int n = g.VerticesCount();
	adjMatrix.resize(n, vector<bool>(n, false));

	for (int i = 0; i < n; ++i)
	{
		vector<int> nextVertices = g.GetNextVertices(i);
		for (int j = 0; j < nextVertices.size(); ++j)
		{
			adjMatrix[i][nextVertices[j]] = true;
		}
	}

}

void MatrixGraph::AddEdge(int from, int to)
{
	int verticesCount = VerticesCount();
	assert(from >= 0 && from < verticesCount);
	assert(to >= 0 && to < verticesCount);
	adjMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
	return adjMatrix.size();
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
	int verticesCount = VerticesCount();
	assert(vertex >= 0 && vertex < verticesCount);
	vector<int> nextVertices;
	for (int i = 0; i < verticesCount; ++i)
	{
		if (adjMatrix[vertex][i])
		{
			nextVertices.push_back(i);
		}

	}
	return nextVertices;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
	int verticesCount = VerticesCount();
	assert(vertex >= 0 && vertex < verticesCount);
	vector<int> prevVertices;
	for (int i = 0; i < verticesCount; ++i)
	{
		if (adjMatrix[vertex][i])
		{
			prevVertices.push_back(i);
		}

	}
	return prevVertices;
}
