#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
// #define f first
// #define s second

void multiply(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b[0].size(); j++){
            for (int k=0; k<a.size(); k++){
                res[i][j] = (0LL + res[i][j] + (1LL * a[i][k] * b[k][j]) % m) % m;
            }
        }
    }

    // copy res to a
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b[0].size(); j++){
            a[i][j]= res[i][j];
        }
    }
}

vector<vector<int>> modPow(vector<vector<int>>& a, ll n){
    if (n==0LL) {
        vector<vector<int>> temp(a.size(), vector<int>(a[0].size(), 0));
        for (int i=0; i<a.size(); i++) temp[i][i]= 1;
        return temp;
    }

    if (n==1LL) return a;

    vector<vector<int>> temp= modPow(a, n>>1);
    multiply(temp, temp);
    if (n & 1LL) multiply(temp, a);

    return temp;
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T=1;
    cin>> T;
    while (T--){
        // start
        //
        ll n=2, t;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int j=0; j<n; j++) cin >> a[0][j];         // can initialize to 1 if no weights are there
        cin >> t;

        for (int i=1; i<n; i++) a[i][i-1]= 1;

        vector<vector<int>> dp(n, vector<int>(1, 0));
        for (int i=0; i<n; i++){
            dp[i][0]= a[0][i];
            for (int j=0; j<i; j++){
                dp[i][0] = (dp[i][0] + (1LL * a[0][j] * dp[i-j-1][0]) % m) % m;
            }
        }

        if (t<=n) {
            cout << dp[t-1][0] << endl;
        } else {
            reverse(dp.begin(), dp.end());
            vector<vector<int>> temp= modPow(a, t-n);
            multiply(temp, dp);
            cout << temp[0][0] << endl;
        }
    }
 
    return 0;
}   