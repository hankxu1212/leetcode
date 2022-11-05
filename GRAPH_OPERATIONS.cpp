#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// ----------------------- adjacency list representation -------------------------------- //
typedef pair<int,int> edge;

class Graph{
    int n;
    vector<vector<edge>> adj;
    // adj[i] = (j, w) is the edge i -> j with weight w
    void DFS_h(int v, bool visited[]); 
public:
    Graph(int V);
    void addEdge(int v, int u, int w);
    vector<int> dijkstra(int s);
    void DFS(int v);
    void BFS(int v);
};

Graph::Graph(int V){
    this->n = V;
    adj = vector<vector<edge>>(V, vector<edge>(0));
}

void Graph::addEdge(int v, int u, int w){
    adj[v].push_back(make_pair(u,w));
    adj[u].push_back(make_pair(v,w));
}

void Graph::DFS_h(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    for (auto &i : adj[v])
        if (!visited[i.first]){
            DFS_h(i.first, visited);
        }
}

void Graph::DFS(int v){
    bool visited[n] = {false};
    DFS_h(v, visited);
}

void Graph::BFS(int v){
    bool visited[n] = {false};
    visited[v] = true;
    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int c = q.front();
        q.pop();
        cout << c << " ";
        for (auto &i : adj[c])
            if (!visited[i.first]){
                visited[i.first] = true;
                q.push(i.first);
            }
    }
}

vector<int> Graph::dijkstra(int s){
    typedef pair<int,int> d;
    // d.first = distance; d.second = vertex (different from edge type)
    priority_queue<d, vector<d>, greater<d>> pq;
 
    vector<int> dist(n, INT_MAX);
 
    pq.push(make_pair(0,s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &i : adj[u]) {
            int v = i.first;
            int w = i.second;
 
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
 
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    return dist;
}
// ----------------------- adjacency list representation -------------------------------- //

// ----------------------- adjacency matrix representation -------------------------------- //
int minDistance(vector<int> dist, vector<bool> visited, int n)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
vector<int> dijkstra_matrix(vector<vector<int>> G, int s, int n)
{
    vector<int> dist(n, INT_MAX); 
    vector<bool> visited(n, false); 
 
    dist[s] = 0;
 
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
 
        for (int v = 0; v < n; v++)
            if (!visited[v] && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v])
                dist[v] = dist[u] + G[u][v];
    }
    return dist;
}
// ----------------------- adjacency matrix representation -------------------------------- //

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.dijkstra(0);

    g.BFS(0);
    cout << "\n";
    g.DFS(0);
    return 0;
}