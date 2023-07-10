// Topological Sort using DFS, O(V+E)
stack<int> s;
vector<int> traversal;
vector<bool> visited;

void dfs(vector<int> adj[], int i){
    visited[i]= 1;
    for (int next: adj[i]){
        if (!visited[next])
            dfs(adj, next);
    }
    s.push(i);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    visited= vector<bool>(V,false);
    for (int i=0; i<V; i++){
        if (!visited[i])
            dfs(adj, i);
    }
    while (!s.empty()) {
        traversal.push_back(s.top());
        s.pop();
    }
    return traversal;
}