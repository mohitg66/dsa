// Vector (ascending)
bool cmp(auto a, auto b) {
    return a < b;
}
sort(v.begin(), v.end(), cmp);

// Vector of pairs (first ascending, second ascending)
bool cmp(auto &a, auto &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
sort(v.begin(), v.end(), cmp);

// Min heap
// priority_queue<int, vector<int>, greater<>> pq;
struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp> pq;

// Set (ascending)
struct cmp {
    bool operator()(int a, int b) {
        return a < b;
    }
};
set<int, cmp> s;

// Map (key ascending)
struct cmp {
    bool operator()(int a, int b) {
        return a < b;
    }
};
map<int, int, cmp> m;