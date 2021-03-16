// Code By : Akshay Jain

#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> BridgeEdge_Set;

// Function to find whether the graph is 2-Edge Connected using Depth-First Search Algorithm
int DFS(vector<int> adj[], int v, vector<bool> visited, int arrival[], int parent, int &time)
{
	visited[v] = true;
	arrival[v] = ++time;

	int deepest_BE = arrival[v];

	for (auto w = adj[v].begin(); w != adj[v].end(); ++w)
	{
		if (!visited[*w])
			deepest_BE = min(deepest_BE, DFS(adj, *w, visited, arrival, v, time));
		else if (*w != parent)
			deepest_BE = min(deepest_BE, arrival[*w]);
	}

	if (deepest_BE == arrival[v] && parent != -1)
	{
		pair<int, int> BridgeEdge = make_pair(parent + 1, v + 1);
		BridgeEdge_Set.insert(BridgeEdge);
	}
	return deepest_BE;
}

// Function to add edge into the list
void addEdge_List(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Function to display the Final Result
void display(const set<pair<int, int>> &s)
{
	if (s.size() > 0)
	{
		cout << endl
			 << "The given graph is not 2-Edge Connected.\nThe Bridge Edges are :- ";
		for (auto const &BE : s)
			cout << "(" << BE.first << ", " << BE.second << ")"
				 << " ";
		cout << endl;
	}
	else
		cout << endl
			 << "The given graph is 2-Edge Connected" << endl;
}

int main()
{
	// Input the no. of Vertices
	int vertices;
	do
	{
		cout << "Enter the no of total vertices in the graph : ";
		cin >> vertices;
		if (vertices < 1)
			cout << "vertices cannot be less than one, Enter again!" << endl;
	} while (vertices < 1);

	// Input the no. of Edges
	int edges;
	do
	{
		cout << "Enter the no of total edges in the graph : ";
		cin >> edges;
		if (edges < 0)
			cout << "edges cannot be less than zero, Enter again!" << endl;
	} while (edges < 0);

	vector<int> adjacency_List[vertices];

	// Input the Edges in the Graph
	for (int i = 1; i <= edges; i++)
	{
		int u, v;
		bool flag = true;

		while (flag)
		{
			cout << "Enter the Edge " << i << " Vertices : ";
			cin >> u >> v;
			if (u < 1 || u > vertices || v < 1 || v > vertices)
				cout << "Vertices out of bounds, Enter again!" << endl;
			else
				flag = false;
		}

		addEdge_List(adjacency_List, u - 1, v - 1);
	}

	int start = 0, parent = -1, time = 0;
	vector<bool> visited(vertices);
	int arrival[vertices];

	DFS(adjacency_List, start, visited, arrival, parent, time);
	display(BridgeEdge_Set);
	return 0;
}
