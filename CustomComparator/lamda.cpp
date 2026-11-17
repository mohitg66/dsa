// Vector (ascending)
sort(v.begin(), v.end(), [](auto a, auto b) {
    return a < b;
});

// Vector of pairs (first ascending, second ascending)
sort(v.begin(), v.end(), [](auto &a, auto &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
});

// Min heap
// priority_queue<int, vector<int>, greater<>> pq;
priority_queue<int, vector<int>, decltype([](auto a, auto b) {
    return a > b;
})> pq;

// Set (ascending) (C++20 only)
set<int, decltype([](auto a, auto b) {
    return a < b;
})> s;

// Map (key ascending) (C++20 only)
map<int, int, decltype([](auto a, auto b) {
    return a < b;
})> m;