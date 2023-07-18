// Cycle Detection in Undirected Graph using BFS
queue<pair<int, int>> q;
bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);

    for (int i=0; i<V; i++){
        if (visited[i]) continue;
        q.push({i, -1});
        visited[i]= 1;
        while (!q.empty()){
            pair<int, int> cur= q.front(); q.pop();
            for (int next: adj[cur.first]){
                if (visited[next]){
                    if (next!=cur.second)
                        return true;
                } else {
                    visited[next]= 1;
                    q.push({next, cur.first});
                }
            }
        }
    }
    return false;
}