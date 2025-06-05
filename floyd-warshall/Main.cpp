#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Graph.h"

int main()
{
	int chance = 3;
	srand(time(0));
	int size = 5 + rand() % 10;
	Graph* g = new Graph(size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (rand() % chance == 0)
				g->addVertex(rand() % size, rand() % size, 1 + rand() % 20);
		}
	}
	//Вывод всех кратчайших путей
	g->printInfo();

	system("pause");
	return 0;
}