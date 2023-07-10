// Kosaraju Algorithm for Strongly Connected Components (SCCs)
vector<bool> visited;
stack<int> s;
void dfs(vector<vector<int>>& adj, int i, bool topSort){
    visited[i]= 1;
    for (int next: adj[i]){
        if (!visited[next])
            dfs(adj, next, true);
    }
    if (topSort) s.push(i);
}

int kosaraju(int V, vector<vector<int>>& adj) {
    // topological sort
    visited= vector<bool>(V, false);
    for (int i=0; i<V; i++){
        if (!visited[i])
            dfs(adj, i, true);
    }
    
    // reverse the graph
    vector<vector<int>> adj1(V, vector<int>());
    for (int u=0; u<V; u++){
        for (int v: adj[u]){
            adj1[v].push_back(u);
        }
    }
    
    // one by one pop from stack and dfs
    visited= vector<bool>(V, false);
    int count= 0;
    while (!s.empty()){
        if (!visited[s.top()]){
            dfs(adj1, s.top(), false);
            count++;
        }
        s.pop();
    }
    return count;
}