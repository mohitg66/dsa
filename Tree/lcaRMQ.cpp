#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
// #define M 1000000007
// #define f first
// #define s second

// Segment Tree | Range Query and Point Update
class SegmentTree {
public:
    vector<pi> seg;
    int n;

    SegmentTree(vector<pi>& nums) {
        n= nums.size();
        seg.resize(4*n +1);
        build(0, 0, n-1, nums);
    }

    void build(int i, int low, int high, vector<pi> &nums){
        if (low== high) {
            seg[i]= nums[low];
            return;
        }
        int mid= low+ (high-low)/2;
        build(2*i +1, low, mid, nums);
        build(2*i +2, mid+1, high, nums);
        seg[i] = min(seg[2*i +1], seg[2*i +2]);
    }

    // get the min of elements in the range [left, right]
    pi get(int left, int right, int i=0, int low= 0, int high= -1) {
        if (high == -1) return get(left, right, i, low, n-1);
        if (left > high || right < low || low > high) return {INT_MAX, -1};
        if (left <= low && right >= high) return seg[i];
        int mid= low + (high-low)/2;
        
        return min(get(left, right, 2*i +1, low, mid), get(left, right, 2*i +2, mid+1, high));
    }
};

// get euler tour of tree for lca
void dfs(vector<int> adj[], vector<pi> &tour, vector<int> &pos, int u=0, int p=-1, int d=1){
    tour.push_back({d, u});
    pos[u] = tour.size()-1;
    for (int v: adj[u]){
        if (v == p) continue;
        dfs(adj, tour, pos, v, u, d+1);
        tour.push_back({d, u});
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=1;
    // cin>> T;
    while (T--){
        int n, q;
        cin>> n>> q;
        vector<int> adj[n];
        for (int i=0; i<n-1; i++){
            int u, v;
            cin>> u>> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<pi> tour;        // {depth, node}
        vector<int> pos(n);     // first position of node in tour
        dfs(adj, tour, pos);    // get euler tour

        SegmentTree st(tour);
        while (q--){
            int u, v;
            cin>> u>> v;
            u--; v--;
            pi lca = st.get(min(pos[u], pos[v]), max(pos[u], pos[v]));  // get lca
            cout << tour[pos[u]].first + tour[pos[v]].first - 2*lca.first << endl ;
        }
    }

    return 0;
}