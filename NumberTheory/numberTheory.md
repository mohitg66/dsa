# Number Theory

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

``` c++
// general code for matrix exponentiation
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
```

### Euclidean Algorithm
#### Computing gcd using Euclidean algorithm
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
#### Pre computing all facts and modular inverse of facts
``` c++
class PNC {
private:
    ll m;
    ll modPow(ll a, ll n){
        if (n==0) return 1;
        ll res= modPow((a * a) % m, n/2) % m;
        if (n%2 == 0)
            return res;
        else
            return (a* res) % m;
    }

public:
    vector<ll> f;
    vector<ll> f_inv;
    // m should be a large prime number such as 1e9+7
    PNC(ll n, ll _m= 1e9+7){ 
        m= _m;
        f.resize(n+1);
        f_inv.resize(n+1);

        f[0]= f[1]= 1;
        for (ll i=2; i<=n; i++)
            f[i]= (i * f[i-1]) % m;

        f_inv[n]= modPow(f[n], m-2);
        f_inv[0]= f_inv[1]= 1;
        for (ll i=n-1; i>=2; i--) 
            f_inv[i]= ((i+1) * f_inv[i+1]) % m;
    }
    
    ll ncr(ll n, ll r){
        return (((f[n]* f_inv[n-r]) % m) * f_inv[r]) % m;
    }

    ll npr(ll n, ll r){
        return (f[n]* f_inv[n-r]) % m;
    }
};
```

#### Stars and Bars technique
The number of ways to put $n$ identical objects into $k$ labeled boxes is `nCr(n+k-1, k-1)`