// Tarjan's algorithm for finding bridges in a graph (edges which are not part of any cycle)
vector<bool> visited;
vector<int> tin, low;
set<int> ans;
int timer= 0;

void dfs(vector<int> adj[], int cur, int parent= -1){
    visited[cur]= 1;
    tin[cur]= low[cur]= timer++;
    int children= 0;
    for (int child: adj[cur]){
        if (child==parent) continue;

        if (visited[child]) low[cur]= min(low[cur], tin[child]);

        else {
            dfs(adj, child, cur);
            low[cur]= min(low[cur], low[child]);

            if (low[child]>= tin[cur] && parent != -1) {
                ans.insert(cur);
            }
            children++;
        }
    }
    if (children >1 && parent== -1) ans.insert(cur);
}

public:
vector<int> articulationPoints(int V, vector<int>adj[]) {
    visited.resize(V, false);
    tin.resize(V);
    low.resize(V);
    for (int i=0; i<V; i++){
        if (!visited[i]) dfs(adj, i);
    }
    if (ans.empty()) return {-1};
    else return {ans.begin(), ans.end()};
}