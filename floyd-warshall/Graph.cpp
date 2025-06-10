#include <algorithm>
#include <iostream>

#include "Graph.h"

Graph::Graph() : vertexCount(0), changed(true) {}

Graph::Graph(int size) : vertexCount(size), changed(true) {
	vertexMatrix.resize(size, std::vector<int>(size, INF));
}

Graph::~Graph()
{
}

void Graph::extendMatrix(int add_size) {
	int new_size = vertexCount + add_size;

	//расширение имеющихся векторов
	for (auto& row : vertexMatrix) {
		row.resize(new_size, INF);
	}

	//добавление новых
	for (int i = vertexCount; i < new_size; ++i) {
		vertexMatrix.emplace_back(new_size, INF);
	}

	vertexCount = new_size;
}

void Graph::addVertex(int i, int j, int length) {
	int max_index = std::max(i, j);
	if (max_index >= vertexCount) {
		extendMatrix(max_index - vertexCount + 1);
	}

	if(i != j)
	{
		vertexMatrix[i][j] = length;
		changed = true;
	}
	else {
		vertexMatrix[i][j] = 0;
	}

}

void Graph::removeVertex(int i, int j) {
	if (i < vertexCount && j < vertexCount && i != j) {
		vertexMatrix[i][j] = INF;
		changed = true;
	}
}

int Graph::findShortestWay(int i, int j) {
	if (i >= vertexCount || j >= vertexCount) 
		return -1;
	if (i == j)
		return 0;

	if (changed) {
		//клонирование матрицы путей
		k_vector = vertexMatrix;

		for (int k = 0; k < vertexCount; k++) {
			for (int i = 0; i < vertexCount; i++) {
				if (k_vector[i][k] == INF) 
					continue;

				for (int j = 0; j < vertexCount; j++) {
					if (k_vector[k][j] != INF) {
						k_vector[i][j] = std::min(k_vector[i][k] + k_vector[k][j], k_vector[i][j]);
					}
				}
			}
		}
		changed = false;
	}

	return (k_vector[i][j] == INF) ? -1 : k_vector[i][j];
}

void Graph::printInfo()
{
	std::cout << "All shortest ways(-1 if way does not exists)" << std::endl;
	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = 0; j < vertexCount; j++)
		{
			std::cout << "Way " << i << " -> " << j << ": " << findShortestWay(i, j) << std::endl;

		}
	}
}
