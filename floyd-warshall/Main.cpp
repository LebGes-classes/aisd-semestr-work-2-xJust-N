#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Graph.h"

int main()
{
	srand(time(0));
	int size = 1 + rand() % 10;
	Graph* g = new Graph(size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (rand() % 1 == 0)
				g->addVertex(rand() % size, rand() % size, 1 + rand() % 20);
		}
	}
	//Вывод всех кратчайших путей

	std::cout << "All shortest ways(-1 if way does not exists)" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << "Way " << i << " -> " << j << ": " << g->findShortestWay(i, j) << std::endl;

		}
	}

	system("pause");
	return 0;
}