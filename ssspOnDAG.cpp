// Single Source Shortest Path on DAG

// Topological Sort START
vector<bool> visited;
stack<int> s;
vector<int> topo;

void dfsTopoSort(int n, vector<int> adj[], int cur=0){
    visited[cur]= true;
    for (int child: adj[cur]){
        if (!visited[child])
            dfsTopoSort(n, adj, child);
    }
    s.push(cur);
}

vector<int> topoSort(int n, vector<int> adj[], int start= 0){
    visited= vector<bool>(n, false);
    dfsTopoSort(n, adj, start); // start is the starting node for topological sorted order

    while (!s.empty()) {
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
}
// Topological Sort END

vector<int> ssspOnDAG(int n, vector<int> adj[], int start= 0){
    vecto<int> topo= topoSort(n, adj, start);
    vector<int> dist(n, INT_MAX);
    dist[start]= 0;
    for (int cur: topo){
        for (int child: adj[cur]){
            if (dist[cur]+ 1 < dist[child]){
                dist[child]= dist[cur]+ 1;
            }
        }
    }
    return dist;
}
