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
    void topological_DFS_h(int v, bool visited[], vector<int> &s);
public:
    Graph(int V);
    void addEdge(int v, int u, int w);
    vector<int> dijkstra(int s);
    vector<int> bellman_ford(int s);
    void DFS(int v);
    void BFS(int v);
    vector<int> topological_DFS();
};

Graph::Graph(int V){
    this->n = V;
    adj = vector<vector<edge>>(V, vector<edge>(0));
}

void Graph::addEdge(int v, int u, int w){
    adj[v].push_back(make_pair(u,w));
    // uncomment next line if undirected
    //adj[u].push_back(make_pair(v,w));
}

void Graph::DFS_h(int v, bool visited[]){
    visited[v] = true;
    //cout << v << " ";
    for (auto &i : adj[v]){
        if (!visited[i.first]){
            DFS_h(i.first, visited);
        }
    }
}

void Graph::DFS(int v){
    bool visited[n] = {false};
    DFS_h(v, visited);
}

//ENSURES: s is modified to be in reverse topological order
void Graph::topological_DFS_h(int v, bool visited[], vector<int> &s){
    visited[v] = true;
    for(auto &i : adj[v]){
        if(!visited[i.first]){
            topological_DFS_h(i.first, visited, s);
        }
    }
    cout << v << " ";
    s.push_back(v);
}

//ENSURES: creates a topological sorting of Graph object
vector<int> Graph::topological_DFS(){
    bool visited[n] = {false};
    vector<int> s;
    for(int i=0; i<n; i++)
        topological_DFS_h(i, visited, s);
    reverse(s.begin(), s.end());
    return s;
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

    return dist;
}

vector<int> Graph::bellman_ford(int s){
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    //iterates through V
    for(int i=0;i<n+1;i++){
        bool flag = false;
        //iterates through E
        for(int j=0;j<n;j++){
            //source vertex: j || dest vertex : v.first || weight = v.second
            for(auto &v : adj[j]){
                if(dist[j] != INT_MAX && dist[j] + v.second < dist[v.first]){
                    flag = true;
                    dist[v.first] = dist[j] + v.second;
                }
            }
        }

        if(flag && i == n){
            //we were able to relax the edges further on nth iteration ==> NEGATIVE CYCLE
            cout << "Negative Cycle detected\n";
        }
        else if(!flag){
            //no changes were made ==> WE ARE DONE!
            return dist;
        }
    }
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

void printVec(vector<int> v){
    for (int i = 0; i < v.size(); ++i)
        printf("%d \t\t %d\n", i, v[i]);
}

int main()
{
    int n = 6;
    Graph g(n);
    g.addEdge(5, 2,0);
    g.addEdge(5, 0,0);
    g.addEdge(4, 0,0);
    g.addEdge(4, 1,0);
    g.addEdge(2, 3,0);
    g.addEdge(3, 1,0);

    //printVec(g.dijkstra(0));
    printVec(g.topological_DFS());
    return 0;
}