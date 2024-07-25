#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;  // LOG should be >= log2(MAXN)

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int v, int p) {
    up[v][0] = p;  // the 2^0-th ancestor of v is its parent

    for (int i = 1; i < LOG; i++) {
        if (up[v][i-1] != -1) {
            up[v][i] = up[up[v][i-1]][i-1];  // 2^i-th ancestor
        } else {
            up[v][i] = -1;
        }
    }

    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int kthAncestor(int node, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node = up[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];  // Return the parent of u (or v)
}

int main() {
    int n;  // number of nodes in the tree
    cin >> n;

    // Initializing the up table and depth array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LOG; j++) {
            up[i][j] = -1;
        }
    }
    depth[0] = 0;  // assuming the root node is 0

    // Reading the tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocessing
    dfs(0, -1);  // assuming the root node is 0

    // Example queries
    int node, k;
    cin >> node >> k;
    cout << "The " << k << "-th ancestor of node " << node << " is " << kthAncestor(node, k) << endl;

    int u, v;
    cin >> u >> v;
    cout << "The LCA of node " << u << " and node " << v << " is " << lca(u, v) << endl;

    return 0;
}
