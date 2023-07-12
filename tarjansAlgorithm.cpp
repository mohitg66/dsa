// Tarjan's algorithm for finding bridges in a graph (edges which are not part of any cycle)
vector<bool> visited;
vector<int> tin, low;
vector<vector<int>> bridges;
int timer= 0;

void dfs(vector<int> adj[], int cur, int parent= -1){
    visited[cur]= 1;
    tin[cur]= low[cur]= timer++;
    for (int child: adj[cur]){
        if (child==parent) continue;

        if (visited[child]) low[cur]= min(low[cur], low[child]);

        else {
            dfs(adj, child, cur);
            low[cur]= min(low[cur], low[child]);
            if (low[child]> tin[cur]){
                bridges.push_back({cur, child});
            }
        }
    }
}

vector<vector<int>> tarjansAlgorithm(int V, vector<int> adj[]){
    visited.resize(V, false);
    tin.resize(V);
    low.resize(V);
    dfs(adj, 0);
    return bridges;
}