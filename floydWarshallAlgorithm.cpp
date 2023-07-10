// Floyd Warshall Algorithm for finding all pairs shortest path, O(V^3)

// adj is the adjacency matrix of the graph
void floydWarshallAlgorithm(int n, vector<vector<int>> &matrix){
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==k || j==k || matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX) continue;
                matrix[i][j]= min(matrix[i][j], matrix[i][k]+ matrix[k][j]);
            }
        }
    }
}