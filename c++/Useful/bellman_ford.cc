#include <bits/stdc++.h>

using namespace std;

// Function to implement Bellman-Ford algorithm
void BellmanFord(vector<vector<int>> edges, int V, int E, int start) {
    // Initialize distance array with large values
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    // Relax edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the shortest distance from the start vertex
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        if (dist[i] != INT_MAX) {
            cout << dist[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }
}

int main() {
    int V = 5;    // Number of vertices
    int E = 8;    // Number of edges

    // Vector to store edges in the format (u, v, weight)
    vector<vector<int>> edges = { { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, 
                                  { 1, 3, 2 }, { 1, 4, 2 }, { 3, 2, 5 }, 
                                  { 3, 1, 1 }, { 4, 3, -3 } };

    int start = 0;    // Starting vertex

    BellmanFord(edges, V, E, start);

    return 0;
}

