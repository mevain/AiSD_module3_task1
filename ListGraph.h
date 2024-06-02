#pragma once
#include "iGraph.h"
#include <vector>

using namespace std;

class ListGraph : public IGraph
{
public:
	ListGraph(int vecticesCount);
	ListGraph(const IGraph& graph);

	virtual void AddEdge(int from, int to) override;

	virtual int VerticesCount() const override;

	virtual vector<int> GetNextVertices(int vertex) const override;
	virtual vector<int> GetPrevVertices(int vertex) const override;

private:
	vector < vector<int>> adjList;
	vector < vector<int>> pAdjList;

};
