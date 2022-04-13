#include "Graphy.h"

using namespace std;

Graphy::Graphy() {
}

Graphy::~Graphy() {
}

void Graphy::addEdge(int base, int destination) {
	for (int i : this->vertices[base])
		if (i == destination)
			throw DuplicateEdgeException();
	this->vertices[base].push_back(destination);
}

void Graphy::addVertex(int base) {
	if (!this->vertices.count(base))
		this->vertices.insert(pair<int, vector<int>>(base, vector<int>()));
}

void Graphy::removeEdge(int base, int destination) {
	vector<int> vertices = this->vertices[base];
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i] == destination) {
			this->vertices[base].erase(vertices.begin() + i);
			return;
		}
	}

	throw EdgeNotFoundException();
}

void Graphy::removeVertex(int base) {
	if (this->vertices.count(base))
		this->vertices.erase(base);
	
	for (auto const& x : this->vertices) {
		for (int i = 0; i < x.second.size(); i++) {
			if (x.second[i] == base)
				this->vertices[x.first].erase(this->vertices[x.first].begin() + i);
		}
	}
}

bool Graphy::hasEdge(int base, int destination) {
	return (bool)count(this->vertices[base].begin(), this->vertices[base].end(), destination);
}

bool Graphy::hasVertex(int base)
{
	return (bool)this->vertices.count(base);
}

std::vector<int> Graphy::outEdges(int i) {
	return this->vertices[i];
}

std::vector<int> Graphy::inEdges(int j) {
	std::vector<int> out;

	for (auto const& x : this->vertices) {
		for (int i : x.second) {
			if (i == j) {
				out.push_back(x.first);
				continue;
			}
		}
	}

	return out;
}

std::vector<int> Graphy::depthFirstSearch(int start, int end, std::vector<int> visited) {
	visited.push_back(start);
	if (start == end)
		return visited;
	vector<int> edges = this->vertices[start];

	vector<vector<int>> paths;
	for (int x = 0; x < edges.size(); x++) {
		if (!std::count(visited.begin(), visited.end(), edges[x])) {
			 paths.push_back(depthFirstSearch(edges[x], end, visited));
		}
	}

	if (paths.empty())
		return visited;
	else
		return paths[0];
}

std::vector<int> Graphy::breadthFirstSearch(int start, int end) {
	return this->Dijkstra(start, end, vector<int>());
}

std::vector<int> Graphy::Dijkstra(int start, int end, std::vector<int> currentPath) {
	currentPath.push_back(start);
	if (start == end)
		return currentPath;

	vector<vector<int>> paths;
	for (auto i : this->vertices[start]) {
		if (!std::count(currentPath.begin(), currentPath.end(), i))
			paths.push_back(Dijkstra(i, end, currentPath));
	}

	if (paths.empty())
		return currentPath;

	vector<int> min = paths[0];

	for (int i = 1; i < paths.size(); i++)
		if (min.size() > paths[i].size())
			min = paths[i];

	return min;
}
