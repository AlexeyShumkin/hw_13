#include "graph.h"

Graph::Edge::Edge(const std::string& firstHuman, const std::string& secondHuman) : firstHuman_{ firstHuman }, secondHuman_{ secondHuman } {}

void Graph::addEdge(const std::string& firstHuman, const std::string& secondHuman)
{
	if (!edgeExists(Edge(firstHuman, secondHuman)))
		edges_[edgeCount_++] = Edge(firstHuman, secondHuman);
}

void Graph::pairSearch(const std::string& person)
{	
	if (person != edges_[edgeCount_ - 1].secondHuman_)
	{
		for (int i = 0; i < edgeCount_; ++i)
		{
			int handshakes = 0;
			if (person == edges_[i].firstHuman_)
			{
				for (int j = i; j >= 0 && handshakes < 3; --j)
				{
					if (person != edges_[j].firstHuman_)
					{
						++handshakes;
						std::cout << person << " - " << edges_[j].firstHuman_ << '\n';
					}
				}
				int handshakes = 0;
				int tmp = i;
				for (int j = i + 1; j <= edgeCount_; ++j)
				{
					if (edgeCount_ - tmp == 1)
						std::cout << person << " - " << edges_[j - 1].secondHuman_ << '\n';
					else if (edgeCount_ - tmp == 2)
					{
						std::cout << person << " - " << edges_[j].firstHuman_ << '\n';
						++tmp;
					}
					else
					{
						if (handshakes < 2)
						{
							++handshakes;
							std::cout << person << " - " << edges_[j].firstHuman_ << '\n';
						}
						else
						{
							std::cout << person << " - " << edges_[j - 1].secondHuman_ << '\n';
							break;
						}
					}
				}
			}
		}
	}
	else
	{
		int handshakes = 0;
		for (int i = edgeCount_ - 1; handshakes < 3; --i)
		{
			++handshakes;
			std::cout << person << " - " << edges_[i - 1].secondHuman_ << '\n';
		}
	}
	std::cout << std::endl;
}

bool Graph::edgeExists(Edge edge)
{
	for (const auto& e : edges_)
	{
		if (edge.firstHuman_ == e.firstHuman_ && edge.secondHuman_ == e.secondHuman_)
			return true;
	}
	return false;
}