// 1. Необходимо написать несколько реализаций интерфейса :
//ListGraph, хранящий граф в виде массива списков смежности,
//MatrixGraph, хранящий граф в виде матрицы смежности,
//SetGraph, хранящий граф в виде массива хэш - таблиц / сбалансированных деревьев поиска,
//ArcGraph, хранящий граф в виде одного массива пар{ from, to }.
//Также необходимо реализовать конструктор, принимающий const IGraph& .Такой конструктор должен скопировать переданный граф в создаваемый объект.
//Для каждого класса создавайте отдельные h и cpp файлы.
//Число вершин графа задается в конструкторе каждой реализации.

#include <iostream>
#include <vector>
#include <queue>
#include "ListGraph.h"
#include "ArcGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

using namespace std;

void BFS(const IGraph& graph, int vertex, void(*visit)(int))
{
	vector<bool> visited(graph.VerticesCount(), false);
	queue<int> bfsQ;
	bfsQ.push(vertex);
	visited[vertex] = true;
	while (bfsQ.size() > 0) {
		int current = bfsQ.front();
		bfsQ.pop();
		visit(current);
		vector<int> adjList = graph.GetNextVertices(current);
		for (int i = 0; i < adjList.size(); ++i) {
			if (!visited[adjList[i]]) {
				bfsQ.push(adjList[i]);
				visited[adjList[i]] = true;
			}
		}
	}
}


int main()
{
    ListGraph lgraph(5);
    lgraph.AddEdge(0, 1);
    lgraph.AddEdge(1, 0);
    lgraph.AddEdge(1, 3);
    lgraph.AddEdge(4, 2);
    lgraph.AddEdge(3, 4);

    cout << "BFS for ListGraph: ";
    BFS(lgraph, 1, [](int vertex) { cout << vertex << endl; });
    
    MatrixGraph mgraph(lgraph);
    cout << "BFS for MatrixGraph: ";
    BFS(mgraph, 1, [](int vertex) {cout << vertex << endl; });



    SetGraph sgraph(lgraph);
    cout << "BFS for SetGraph: ";
    BFS(sgraph, 1, [](int vertex) { cout << vertex << endl; });

    ArcGraph agraph(lgraph);

    cout << "BFS for ArcGraph: ";
    BFS(agraph, 1, [](int vertex) { cout << vertex << endl; });

    cout << "Ok" << endl;

    return 0;
}


