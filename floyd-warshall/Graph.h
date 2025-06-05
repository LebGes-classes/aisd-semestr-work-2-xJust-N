#pragma once

#include <vector>
class Graph
{
private:
	int vertexCount;
	std::vector<std::vector<int>> vertexMatrix;
	std::vector<std::vector<int>> k_vector;
	const int INF = 2147483647;
	bool changed;

	void extendMatrix(int size);

public:
	Graph();
	Graph(int size);
	~Graph();
	void addVertex(int i, int j, int length);
	void removeVertex(int i, int j);
	int findShortestWay(int i, int j);
	void printInfo();
};

