# DSA
## Template
``` c++
#include <iostream>
using namespace std;
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin>> t;
    while (t--){
        int n;
        cin>> n;
        
    }

    return 0;
}
```

## Number Theory
### Modular Arithmetic
#### Basic +, -, *
- (a+b) % m = ((a % m) + (b % m)) % m
- (a-b) % m = ((a % m) - (b % m)) % m
- (a*b) % m = ((a % m) * (b % m)) % m
#### Modular Inverse
- b<sup>-1</sup> = b<sup>m-2</sup> % m
- (a/b) % m=  ((a % m) * (b<sup>-1</sup> % m)) % m

### Binary Modular Exponentiation
``` c++
ll pow(ll a, ll n, ll m){
    if (n==0) return 1;
    ll res= pow((a * a) % m, n/2, m) % m;
    if (n%2 == 0)
        return res;
    else
        return (a* res) % m;
}
```

### Binary Matrix Exponentiation
#### General
![image1](images/matrixExponentiation1.png)
#### Fibonacci series
![image2](images/matrixExponentiation2.png)

### Euclidean Algorithm
``` c++
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
```

#### Extended Euclidean Algorithm
``` c++
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```

#### Linear Diophantine Equation
https://cp-algorithms.com/algebra/linear-diophantine-equation.html

### Sieve of Eratosthenes
``` c++
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;

for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (ll)(i*i) <= n) {
        for (int j = i*i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

### Combinatorics
#### Combinatorics
```
Combinatorics
```


## Graphs
### Tarjan's algorithm
``` c++
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
```

### Bellman Ford
``` c++
// Bellman Ford Algorithm for SSSP, can also detect negative cycles, O(V*E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S]= 0;
    
    // relax all the edges V-1 times
    for (int i=0; i<V-1; i++){
        for (auto &edge : edges){
            int u= edge[0];
            int v= edge[1];
            int w= edge[2];
            if (dist[u]+ w < dist[v]) dist[v]= dist[u]+ w;
        }
    }
    
    // try relaxing again
    for (auto &edge : edges){
        int u= edge[0];
        int v= edge[1];
        int w= edge[2];
        if (dist[u]+ w < dist[v]) 
            return {-1};
    }
    
    return dist;
}
```

