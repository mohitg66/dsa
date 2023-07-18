// Cycle Detection in Undirected Graph using DFS
bool dfs(vector<int> adj[], vector<bool> &visited, int cur, int parent){
    for (int next: adj[cur]){
        if (visited[next] && next !=parent) return true;
        if (visited[next]) continue;
        visited[next]= 1;
        if (dfs(adj, visited, next, cur)) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
        if (visited[i]) continue;
        visited[i]= 1;
        if (dfs(adj, visited, i, -1)) return true;
    }
    return false;
}