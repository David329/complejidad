#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

class Grafo
{
	int V;
	list<int> *adj;
public:
	Grafo(int V);
	void addVer(int v, int w);
	void BFS(int s);
	//dfs
	void DFSS(int v, bool visited[]);
	void DFS(int v);
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::addVer(int v, int w)
{
	adj[v].push_back(w);
}

void Grafo::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)visited[i] = false;
	list<int> cola;
	visited[s] = true;
	cola.push_back(s);
	list<int>::iterator i;

	while (!cola.empty())
	{
		s = cola.front();
		cout << s << " ";
		cola.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
			{
				visited[*i] = true;
				cola.push_back(*i);
			}
	}
}
void Grafo::DFSS(int v, bool visited[])
{
	visited[v] = true; 
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSS(*i, visited);
}

void Grafo::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	DFSS(v, visited);
}

void main()
{
	Grafo g(4);
	g.addVer(0, 1);
	g.addVer(0, 2);
	g.addVer(1, 2);
	g.addVer(2, 0);
	g.addVer(2, 3);
	g.addVer(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);

	system("pause");
}





/*N REINAS BACKTRACKING
#define N 4
#include<stdio.h>

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i<N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
bool solveNQUtil(int board[N][N], int col)
{
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
	};

	if (solveNQUtil(board, 0) == false)
	{
		printf("Solution does not exist");
		return false;
	}

	printSolution(board);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}
*/