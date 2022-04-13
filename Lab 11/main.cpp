#include <iostream>

#include "Graphy.h"

using namespace std;

int main(void) {

	Graphy graph = Graphy();

	bool connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "Graph Function Testing Menu\n\n [1] Add Edge\n [2] Remove Edge\n [3] Has Edge\n [4] Out Edges\n" <<
			" [5] In Edges\n [6] DFS\n [7] BFS\n";
		int choice = 0;
		std::cin >> choice;
		bool correct = true;
		int base, dest;
		switch (choice) {
		case 1:
			while (correct) {

				std::cout << "\nYou selected [1] Add Edge. The following data will need to be provided:\n" <<
					"Base Number | Destination Number\n\n";
				std::cout << "Please provide the following data in order (Press Enter): Base, Destination\n";
				std::cin >> base >> dest;
				std::cout << "\n     Base: " << base << "\n   Destination: " << dest << "\n";
				std::cout << "\nIs this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;

				if (!correct) { 
					graph.addEdge(base, dest);
				}
			}
			break;
		case 2:
			while (correct) {
				std::cout << "\nYou selected [2] Remove Edge. Please provide a base and destination: ";
				std::cin >> base, dest;
			
				std::cout << "\nYou entered: " << dest << " -> " << dest << ". Is this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;
				if (!correct) { 
					if (graph.hasEdge(base, dest)) {
						graph.removeEdge(base, dest);
					}
					else {
						std::cout << "\nEdge may not be in graph\n";
					}
				}
			}
			break;
		case 3:
			std::cout << "\nYou selected [3] Has Edge. Please provide a base and destination: ";
			std::cin >> base, dest;
			if (graph.hasEdge(base, dest)) {
				std::cout << "This Edge DOES Exists." << endl;
			}
			else {
				std::cout << "This Edge DOES NOT Exist " << endl;
			}
			break;
		case 4:
			std::cout << "\nYou selected [4] Out Edges. Please provide a base: " << endl;
			std::cin >> base;
			if (!graph.outEdges(base).size()) {
				std::cout << "There are no edges going out of this point." << endl;
			}
			else {
				vector<int> ret = graph.outEdges(base);
				std::cout << base << "has edges that go to:\n\n";
				for (int x = 0, x < ret.size(); x++) {
					std::cout << ret(x) << ", ";
				} 
			}
			break;
		case 5:
			std::cout << "\nYou selected [5] In Edges. Please provide a destination: " << endl;
			std::cin >> dest;
			if (graph.inEdges(dest) == vector::empty) {
				std::cout << dest << "has edges that come from:\n\n" << endl;
			}
			else {
				vector<int> ret = graph.inEdges();
				std::cout << "These are the in edges:\n\n";
				for (int x = 0; x < ret.size(); x++) {
					std::cout << ret(x) << ", ";
				} 
			}
			break;
		case 6:
			std::cout << "\nYou selected [6] DFS. Please provide a base and destination: ";
			std::cin >> base, dest;

			if (graph.hasVertex(base) && graph.hasVertex(dest)) {
				std::vector<int> retV;
				retV = graph.depthFirstSearch(base, dest, std::vector<int>());

				for (int x = 0, x < retV.size(); x++) {
					std::cout << retV[x] << " -> ";
				} 
			}
			break;
		case 7:
			std::cout << "\nYou selected [7] BFS. Please provide a base and destination: ";
			std::cin >> base, dest;

			if (graph.hasVertex(base) && graph.hasVertex(dest)) {
				std::vector<int> retV;
				retV = graph.breadthFirstSearch(base, dest);

				for (int x = 0, x < retV.size(); x++) {
					std::cout << retV[x] << " -> ";
				} 			
			}
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