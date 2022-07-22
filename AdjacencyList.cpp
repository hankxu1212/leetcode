#include "pch.h"
#include <iostream>
using namespace std;

const int MAXEDGE = 100;
const int MAXVERTEX = 100;
int head[MAXVERTEX];
int inDegree[MAXVERTEX];
int outDegree[MAXVERTEX];
int cnt;
int numOfVertex;
int numOfEdge;

struct Edge {
	int next;
	int to;
	int val;
}edge[MAXEDGE];

void addEdge(int x, int y, int v) {
	edge[++cnt].next = head[x]; //make this edge point to the head of the list as its "next" variable
	edge[cnt].to = y;
	edge[cnt].val = v;
	inDegree[y]++;
	outDegree[x]++;
	head[x] = cnt; //make the new edge the head of the list
}

void printList() {
	for (int i = 1; i <= numOfVertex; ++i) {
		for (int j = head[i]; j; j = edge[j].next)
			cout << "Node " << i << " points to node " << edge[j].to << " with value " << edge[j].val
			<< " and inDegree value of " << inDegree[i] << endl;
	}
}

int main()
{
	cin >> numOfVertex >> numOfEdge;
	addEdge(1, 2, 4);
	addEdge(2, 4, 2);
	addEdge(2, 3, 5);
	addEdge(4, 5, 9);
	addEdge(6, 5, 2);
	addEdge(6, 4, 2);
	addEdge(7, 8, 1);
	printList();
}