#include "graph.h"

int main()
{
	using namespace std::string_literals;
	setlocale(LC_ALL, "ru");
	Graph g;
	g.addEdge("Олег"s, "Никита"s);
	g.addEdge("Никита"s, "Настя"s);
	g.addEdge("Настя"s, "Ваня"s);
	g.addEdge("Ваня"s, "Женя"s);
	g.pairSearch("Олег"s);
	g.pairSearch("Никита"s);
	g.pairSearch("Настя"s);
	g.pairSearch("Ваня"s);
	g.pairSearch("Женя"s);
}