// Lazy Dijkstra (SSSP) (using visited array)
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    q.push({0, S});
    dist[S]= 0;
    while (!q.empty()){
        int u= q.top().second;
        q.pop();
        if (visited[u]) continue;
        visited[u]= true;

        for (auto edge: adj[u]) {
            int v = edge[0];
            int w = edge[1];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}