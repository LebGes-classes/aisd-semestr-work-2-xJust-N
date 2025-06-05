#include "Graph.h"

#include <algorithm>
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
	vertexMatrix[i][j] = length;
	changed = true;
}

void Graph::removeVertex(int i, int j) {
	if (i < vertexCount && j < vertexCount) {
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
		k_vector = vertexMatrix;

		for (int k = 0; k < vertexCount; ++k) {
			for (int a = 0; a < vertexCount; ++a) {
				
				if (k_vector[a][k] == INF) 
					continue;

				for (int b = 0; b < vertexCount; ++b) {
					
					if (k_vector[k][b] != INF) {
						int new_path = k_vector[a][k] + k_vector[k][b];
					
						if (new_path < 0) 
							continue;
						if (k_vector[a][b] > new_path) {
							k_vector[a][b] = new_path;
						}
					}
				}
			}
		}
		changed = false;
	}

	return (k_vector[i][j] == INF) ? -1 : k_vector[i][j];
}