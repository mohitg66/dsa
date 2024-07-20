// string hashing function, for substrings of given string, in O(1)

vector<int> h(400001);
void compute_hash(const string &s){
    int p = 31;     // using 31 as only lowercase letters are used
    // int p = 53;     // using 53 if both lowercase and uppercase letters are used
    int pp = 1;
    int i= 0;
    for (char c : s){
        h[i] = (1LL * ((i==0) ? 0 : h[i-1]) + 1LL * (c - 'a' + 1) * pp) % M;
        pp = (1LL * pp * p) % M;
        i++;
    }
}

vector<int> pi_inv(400001, 0);
int pi = 1;
for (int i=0; i<400001; i++) {
    pi_inv[i] = pow(pi, M-2, M);
    pi = (1LL * pi * 31) % M;
}

int get(int i, int j){
    // pi_inv[i] is the modular inverse of p^i, pre-computed
    return (int)(1LL * ((1LL * h[j] - ((i==0) ? 0 : h[i-1]) + M) % M) * pi_inv[i] % M);
}