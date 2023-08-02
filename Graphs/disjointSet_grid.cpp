class DisjointSet {
public:
    vector<int> size;
    vector<int> parent;

    // initialization, works for both 0 and 1-based indexing
    DisjointSet(int n, int m){
        size.resize(n*m +1, 1);
        parent.resize(n*m +1);
        for (int i=0; i<n*m +1; i++) parent[i]= i;
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

        int bigger = (size[ulp_u] >= size[ulp_v]) ? ulp_u : ulp_v;  // (rank[ulp_u] >= rank[ulp_v]) ? ulp_u : ulp_v;
        int smaller= (size[ulp_u] >= size[ulp_v]) ? ulp_v : ulp_u;  // (rank[ulp_u] >= rank[ulp_v]) ? ulp_v : ulp_u;
        parent[smaller]= bigger;
        size[bigger] += size[smaller];  // if (rank[bigger]== rank[smaller]) rank[bigger]++;
    }
};