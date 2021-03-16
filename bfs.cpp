// Code By : Akshay Jain

#include <bits/stdc++.h>
using namespace std;

#define MAX 107
int diameter[MAX];

// Function to perform BFS and return the farthest vertice index using Adjacency List
int BFS(vector<int> adj[], int s, int V)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		diameter[i] = 0;
	}

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		queue.pop_front();

		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;

				diameter[*i] = diameter[s] + 1;
				queue.push_back(*i);
			}
		}
	}

	// return index of max value in diameter
	int index = int(max_element(diameter, diameter + V) - diameter);
	return index;
}

// Function to add edge into the list
void addEdge_List(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
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
		{
			cout << "vertices cannot be less than one, Enter again!" << endl;
		}
	} while (vertices < 1);

	// Input the no. of Edges
	int edges;
	do
	{
		cout << "Enter the no of total edges in the graph : ";
		cin >> edges;
		if (edges < 0)
		{
			cout << "edges cannot be less than zero, Enter again!" << endl;
		}
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
			{
				cout << "Vertices out of bounds, Enter again!" << endl;
			}
			else
				flag = false;
		}

		addEdge_List(adjacency_List, u - 1, v - 1);
	}

	int index_1 = BFS(adjacency_List, 0, vertices);
	int index_2 = BFS(adjacency_List, index_1, vertices);

	cout << endl
		 << "The Diameter of the Graph : " << diameter[index_2] << endl;
	return 0;
}
