// Topological Sort using BFS (Kahn's Algorithm), O(V+E)
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> traversal;

    for (int i=0; i<V; i++){
        for (int next: adj[i]){
            inDegree[next]++;
        }
    }

    for (int i=0; i<V; i++){
        if (inDegree[i]==0) q.push(i);
    }

    while (!q.empty()){
        int cur= q.front(); q.pop();
        traversal.push_back(cur);
        for (int next: adj[cur]){
            inDegree[next]--;
            if (inDegree[next]==0)
                q.push(next);
        }
    }
    return traversal;
}