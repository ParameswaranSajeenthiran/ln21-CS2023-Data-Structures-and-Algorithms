
#include <iostream>
using namespace std;

// No of vertices in graph
#define V 6

// A utility function to find the	vertex with minimum key
int finMinKey(int key[], bool MSTVertices[])
{
	int min = INT16_MAX, minIndex;

	for (int v = 0; v < V; v++)
		if (MSTVertices[v] == false && key[v] < min)
			min = key[v], minIndex = v;

	return minIndex;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void MSTPrisms(int G[V][V])
{
	// Key values used to pick minimum weight edge in cut
	int key[V];
	// Array to store constructed MST
	int parent[V];

	// To represent set of vertices included in MST
	bool MSTVertices[V];

	for (int i = 0; i < V; i++)
		key[i] = INT16_MAX, MSTVertices[i] = false;
	key[0] = 0;
	parent[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = finMinKey(key, MSTVertices);

		// Add the picked vertex to the MST Set
		MSTVertices[u] = true;

			for (int v = 0; v < V; v++)

		if (G[u][v] && MSTVertices[v] == false
				&& G[u][v] < key[v])
				parent[v] = u, key[v] = G[u][v];
	}

	printMST(parent, G);
}

int main()
{
	int graph[V][V] = {
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };

	MSTPrisms(graph);

	return 0;
}

