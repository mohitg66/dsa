// Prim's Algorithm for minimum spanning tree, O(V+ ElogE)
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<bool> visited(V, false);
    int sum= 0;

    q.push({0, 0});
    while (!q.empty()){
        int u= q.top().second;
        int w0= q.top().first;
        q.pop();
        if (visited[u]) continue;
        
        visited[u]= true;
        sum+= w0;

        for (auto edge: adj[u]) {
            int v = edge[0];
            int w = edge[1];

            if (!visited[v]) 
                q.push({w, v});
        }
    }
    return sum;
}