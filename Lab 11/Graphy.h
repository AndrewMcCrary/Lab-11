#pragma once
#include <vector>
#include <map>
#include <exception>

class Graphy {
private:
	std::map<int, std::vector<int>> vertices;
	std::vector<int> Dijkstra(int start, int end, std::vector<int> currentPath);
public:
	Graphy();
	~Graphy();
	void addEdge(int base, int destination);
	void addVertex(int base);
	void removeEdge(int base, int destination);
	void removeVertex(int base);
	bool hasEdge(int base, int destination);
	bool hasVertex(int base);
	std::vector<int> outEdges(int i);
	std::vector<int> inEdges(int j);

	std::vector<int> depthFirstSearch(int start, int end, std::vector<int> visited);
	std::vector<int> breadthFirstSearch(int start, int end);
};

struct EdgeNotFoundException : public std::exception
{
	const char* what() const throw ()
	{
		return "The edge does not exist.";
	}
};

struct DuplicateEdgeException : public std::exception
{
	const char* what() const throw ()
	{
		return "The edge already exists.";
	}
};