// Bellman Ford Algorithm for SSSP, can also detect negative cycles, O(V*E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S]= 0;
    
    // relax all the edges V-1 times
    for (int i=0; i<V-1; i++){
        for (auto &edge : edges){
            int u= edge[0];
            int v= edge[1];
            int w= edge[2];
            if (dist[u]+ w < dist[v]) dist[v]= dist[u]+ w;
        }
    }
    
    // try relaxing again
    for (auto &edge : edges){
        int u= edge[0];
        int v= edge[1];
        int w= edge[2];
        if (dist[u]+ w < dist[v]) 
            return {-1};
    }
    
    return dist;
}