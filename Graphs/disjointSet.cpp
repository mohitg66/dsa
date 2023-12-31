// Disjoint Set data structure with union by size, mainly used to detect cycles in kruskal's algorithm
class DisjointSet {
    vector<int> size;   // vector<int> rank;
    vector<int> parent;

    public:
    // initialization, works for both 0 and 1-based indexing
    DisjointSet(int n){
        size.resize(n+1, 1);    // rank.resize(n+1, 0);
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

        int bigger = (size[ulp_u] >= size[ulp_v]) ? ulp_u : ulp_v;  // (rank[ulp_u] >= rank[ulp_v]) ? ulp_u : ulp_v;
        int smaller= (size[ulp_u] >= size[ulp_v]) ? ulp_v : ulp_u;  // (rank[ulp_u] >= rank[ulp_v]) ? ulp_v : ulp_u;
        parent[smaller]= bigger;
        size[bigger] += size[smaller];  // if (rank[bigger]== rank[smaller]) rank[bigger]++;
    }
};