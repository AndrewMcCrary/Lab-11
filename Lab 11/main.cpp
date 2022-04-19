#include <iostream>

#include "Graphy.h"

using namespace std;

int main(void) {

	Graphy graph;

	graph.addVertex(1);
	graph.addVertex(3);
	graph.addVertex(5);
	graph.addVertex(7);
	graph.addVertex(9);
	graph.addVertex(11);

	graph.addEdge(1, 5);
	graph.addEdge(1, 7);
	graph.addEdge(1, 3);
	graph.addEdge(5, 3);
	graph.addEdge(3, 9);
	graph.addEdge(3, 1);
	graph.addEdge(11, 7);

	bool connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "\nGraph Function Testing Menu\n\n [1] Add Edge\n [2] Remove Edge\n [3] Has Edge\n [4] Add Vertex\n [5] Remove Vertex\n [6] Has Vertex\n [7] Out Edges\n" <<
			" [8] In Edges\n [9] DFS\n [10] BFS\n";
		int choice = 0;
		std::cin >> choice;
		bool correct = true;
		int base, dest;
		switch (choice) {
		case 1:
			std::cout << "\nYou selected [1] Add Edge. The following data will need to be provided:\n" <<
				"Base Number | Destination Number\n\n";
			std::cout << "Please provide the following data.\nEnter a base: ";
			std::cin >> base;
			std::cout << "Enter a destination: ";
			std::cin >> dest;

			if (graph.hasEdge(base, dest))
				std::cout << "Edge already exists. \n";
			else if (!(graph.hasVertex(dest)) || !graph.hasVertex(base))
				std::cout << "The base or destination you have entered does not exist. \n";
			else {
				graph.addEdge(base, dest);
				std::cout << "Edge has been added. \n";
			}
			break;
		case 2:
			while (correct) {
				std::cout << "\nYou selected [2] Remove Edge. Please provide the following data.\nEnter a base: ";
				std::cin >> base;
				std::cout << "Enter a destination: ";
				std::cin >> dest;
			
				std::cout << "\nYou entered: " << base << " -> " << dest << ". Is this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;
				if (!correct) {
					if (!graph.hasEdge(base, dest))
						std::cout << "Edge does not exist. \n";
					else if (!graph.hasVertex(base) || !graph.hasVertex(dest))
						std::cout << "The edge or destination you have entered does not exist. \n";
					else {
						graph.removeEdge(base, dest);
						std::cout << "Edge has been removed. \n";
					}
				}
			}
			break;
		case 3:
			std::cout << "\nYou selected [3] Has Edge. Please provide the following data.\nEnter a base: ";
			std::cin >> base;
			std::cout << "Enter a destination: ";
			std::cin >> dest;

			if (graph.hasEdge(base, dest))
				std::cout << "This Edge DOES Exists." << endl;
			else
				std::cout << "This Edge DOES NOT Exist " << endl;
			break;
		case 4:
			std::cout << "\nYou selected [4] Add Vertex. Please provide the following data.\nEnter a vertex: ";
			cin >> base;
			graph.addVertex(base);
			std::cout << "\nThe vertex has been added. If the vertex already existed nothing happened." << endl;

			break;
		case 5:
			std::cout << "\nYou selected [5] Remove Vertex. Please provide the following data.\nEnter a vertex: ";
			cin >> base;
			graph.removeVertex(base);
			std::cout << "\nThe vertex and all adjacent edges have been removed." << endl;
			break;
		case 6:
			std::cout << "\nYou selected [6] Has Vertex. Please provide the following data.\nEnter a vertex: ";
			std::cin >> base;

			if (graph.hasVertex(base))
				std::cout << "This vertex DOES Exists." << endl;
			else
				std::cout << "This vertex DOES NOT Exist " << endl;
			break;
		case 7:
			std::cout << "\nYou selected [7] Out Edges. Please provide the following data.\nEnter a base: ";
			std::cin >> base;
			
			if (graph.outEdges(base).empty()) 
				std::cout << "There are no edges going out of this point or vertex may not exist." << endl;
			else {
				vector<int> ret = graph.outEdges(base);
				std::cout << base << " has edges that go to: ";
				for (int x = 0; x < ret.size(); x++) {
					std::cout << ret[x] << ", ";
				} 
			}
			break;
		case 8:
			std::cout << "\nYou selected [8] In Edges. Please provide the following data.\nEnter a destination: ";
			std::cin >> dest;
			if (graph.inEdges(dest).empty())
				std::cout << "There are no edges going into this point or vertex may not exist." << endl;
			else {
				vector<int> ret = graph.inEdges(dest);
				std::cout << dest << " has edges that come from: ";
				for (int x = 0; x < ret.size(); x++) {
					std::cout << ret[x] << ", ";
				} 
			}
			break;
		case 9:
			std::cout << "\nYou selected [9] DFS. Please provide the following data.\nEnter a base: ";
			std::cin >> base;
			std::cout << "Enter a destination: ";
			std::cin >> dest;

			if (graph.hasVertex(base) && graph.hasVertex(dest)) {
				std::vector<int> retV;
				retV = graph.depthFirstSearch(base, dest, std::vector<int>());
				if (!(retV.empty())) {
					std::cout << retV[0];
					for (int x = 1; x < retV.size(); x++) {
						std::cout << " -> " << retV[x];
					}
				}
			}
			else
				std::cout << "There is no path.";
			break;
		case 10:
			std::cout << "\nYou selected [10] BFS. Please provide the following data.\nEnter a base: ";
			std::cin >> base;
			std::cout << "Enter a destination: ";
			std::cin >> dest;

			if (graph.hasVertex(base) && graph.hasVertex(dest)) {
				std::vector<int> retV;
				retV = graph.breadthFirstSearch(base, dest);
				if (!(retV.empty())) {
					std::cout << retV[0];
					for (int x = 1; x < retV.size(); x++) {
						std::cout << " -> " << retV[x];
					}
				}
			}
			else
				std::cout << "There is no path.";
			break;
		default:
			continue;
		};
		std::cout << "\nContinue? [0 = yes/1 = no]: ";
		std::cin >> connectionTerminated;
	}
}



//int main(void) {
//	Graphy g;

//	g.addVertex(1);
//	g.addVertex(2);
//	g.addVertex(3);
//	g.addVertex(4);
//	g.addVertex(5);

//	g.addEdge(1, 5);
//	g.addEdge(5, 3);
//	g.addEdge(3, 4);
//	g.addEdge(3, 2);
//	g.addEdge(4, 2);

//	vector<int> path = g.breadthFirstSearch(1, 2);
//	for (int i = 0; i < path.size(); i++) {
//		cout << path[i] << endl;
//	}

//	return 0;
//}