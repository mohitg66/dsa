// Kruskal's Algorithm for minimum spanning tree, O(V+ ElogE)
class DisjointSet {
    vector<int> size;
    vector<int> parent;

    public:
    // initialization, works for both 0 and 1-based indexing
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<n+1; i++){
            parent[i]= i;
        }
    }
    
    // returns the ultimate parent of u
    int find(int u){
        if (u== parent[u]) return u;
        parent[u]= find(parent[u]);
        return parent[u];
    }

    // union by size: combines u and v
    void unionBySize(int u, int v){
        int ulp_u= find(u);
        int ulp_v= find(v);

        if (ulp_u == ulp_v) return;

        int bigger = (size[ulp_u] >= size[ulp_v]) ? ulp_u : ulp_v;
        int smaller= (size[ulp_u] >= size[ulp_v]) ? ulp_v : ulp_u;
        parent[smaller]= bigger;
        size[bigger] += size[smaller];
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<vector<int>> edges;
    for (int u=0; u<V; u++){
        for (auto edge : adj[u]){
            edges.push_back({edge[1], u, edge[0]});
        }
    }
    sort(edges.begin(), edges.end());
    
    DisjointSet set(V);
    int sum= 0, count= 0;
    for (auto edge : edges){
        int u= edge[1];
        int v= edge[2];
        int w= edge[0];
        if (set.find(u) == set.find(v)) continue;
        set.unionBySize(u, v);
        sum+= w;
        count++;
        if (count==V-1) break;
    }
    return sum;
}