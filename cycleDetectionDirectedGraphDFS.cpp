// Cycle Detection in Directed Graph using DFS
bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited, int cur, int parent){
    visited[cur]= 1;
    dfsVisited[cur]= 1;
    for (int next: adj[cur]){
        if (visited[next] && dfsVisited[next]) return true;
        if (visited[next]) continue;
        if (dfs(adj, visited, dfsVisited, next, cur)) return true;
    }

    dfsVisited[cur]= 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> dfsVisited(V, false);
    for(int i=0; i<V; i++){
        if (visited[i]) continue;
        if (dfs(adj, visited, dfsVisited, i, -1)) return true;
    }
    return false;
}