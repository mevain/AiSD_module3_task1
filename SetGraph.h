#pragma once
#pragma once
#include "iGraph.h"
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class SetGraph : public IGraph {
private:
    vector<unordered_set<int>> adjSet;
    vector<set<int>> prevSet;
public:
    SetGraph(int vertexCount);
    SetGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual vector<int> GetNextVertices(int vertex) const override;
    virtual vector<int> GetPrevVertices(int vertex) const override;
};