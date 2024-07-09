#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define m 1000000007
// #define f first
// #define s second

double dist(vector<int> &a, vector<int> &b){
    return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
}

double solve(int n, vector<vector<int>> &p){
    vector<vector<double>> dp(1<<n, vector<double>(n, 1e11));
    for (int i=0; i<n; i++) dp[(1<<n)-1][i]= 0;

    vector<vector<int>> bitmap(n);
    for (int i=0; i< (1<<n)-1; i++) 
        bitmap[__builtin_popcount(i)].push_back(i);

    for (int i=n-1; i>0; i--){
        for (int b : bitmap[i]){
            for (int last = 0; last < n; last++){
                if (!(1<<last & b)) continue;       // if last is not in b then continue
                for (int k=0; k< n; k++){
                    if (1<<k & b) continue;         // if k is already in b then continue
                    dp[b][last]= min(dp[b][last], dist(p[last], p[k]) + dp[b | 1<<k][k]);
                }
            }
        }
    }

    double ans= 1e11;
    for (int b: bitmap[1])
        ans = min(ans, dp[b][__builtin_ctz(b)]);

    return ans;
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T=1;
    // cin>> T;
    while (T--){

        int n;
        cin >> n;
        vector<vector<int>> points(n);
        for (int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }
    
        double ans = solve(n, points);
        cout << fixed << setprecision(3) << ans << endl;

    }
    
    return 0;
}   