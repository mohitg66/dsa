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



// C++20 only
// Set (ascending)
set<int, decltype([](auto a, auto b) {
    return a < b;
})> s;




// Map (key ascending)
map<int, int, decltype([](auto a, auto b) {
    return a < b;
})> m;