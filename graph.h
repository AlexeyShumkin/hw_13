#pragma once
#include <iostream>
#include <string>
#define SIZE 5

class Graph 
{
public:
	Graph() = default;
	void addEdge(const std::string& firstHuman, const std::string& secondHuman);
	void pairSearch(const std::string& person);
private:
	struct Edge
	{
		Edge() = default;
		Edge(const std::string& firstHuman, const std::string& secondHuman);
		std::string firstHuman_;
		std::string secondHuman_;
	};
	Edge edges_[SIZE * SIZE];
	bool edgeExists(Edge edge);
	int edgeCount_{ 0 };
};

