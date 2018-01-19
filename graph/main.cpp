#include <stdlib.h>
#include <iostream>
#include "graph.h"

int main()
{
	ds::graph g;

		
	std::cout << "Adding 5 vertecies: ";
	std::cout << g.addNode() << " ";
	std::cout << g.addNode() << " ";
	std::cout << g.addNode() << " ";
	std::cout << g.addNode() << " ";
	std::cout << g.addNode() << " ";
	std::cout << std::endl;

	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);

	g.print();


	//dfs print
	g.dfsPrint(0);
	g.dfsPrint(1);

	//bfs print
	g.bfsPrint(0);
	g.bfsPrint(1);
	g.bfsPrint(2);
	g.bfsPrint(3);
}
