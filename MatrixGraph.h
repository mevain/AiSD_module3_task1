#pragma once
#include "iGraph.h"
#include <vector>

using namespace std;

class MatrixGraph : public IGraph
{
public:
	MatrixGraph(int verticesCount);
	MatrixGraph(const IGraph& g);

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;
	virtual vector<int> GetNextVertices(int vertex) const override;
	virtual vector<int> GetPrevVertices(int vertex) const override;

private:
	vector<vector<bool>> adjMatrix;
};