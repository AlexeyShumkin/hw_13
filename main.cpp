#include "graph.h"

int main()
{
	using namespace std::string_literals;
	setlocale(LC_ALL, "ru");
	Graph g;
	g.addEdge("����"s, "������"s);
	g.addEdge("������"s, "�����"s);
	g.addEdge("�����"s, "����"s);
	g.addEdge("����"s, "����"s);
	g.pairSearch("����"s);
	g.pairSearch("������"s);
	g.pairSearch("�����"s);
	g.pairSearch("����"s);
	g.pairSearch("����"s);
}