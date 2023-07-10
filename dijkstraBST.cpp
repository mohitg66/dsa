// BST Dijkstra (SSSP) (using set)
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    set<pair<int, int>> PQ;
    vector<int> dist (V, INT_MAX);
    dist[S] = 0;

    PQ.insert({0, S});
    while (!PQ.empty()) {
        int u = PQ.begin()->second;
        PQ.erase(PQ.begin());
        for (auto edge : adj[u]) {
            int v = edge[0], w = edge[1];
            if (dist[u]+ w < dist[v]) {
                PQ.erase({dist[v], v});
                dist[v] = dist[u]+ w;
                PQ.insert({dist[v], v});
            }
        }
    }
    return dist;
}