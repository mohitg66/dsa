// Segment Tree with Lazy Propagation | Range Update and Range Query
class SegmentTree {
public:
    vector<ll> seg, lazy;
    int n;

    SegmentTree(vector<int>& nums) {
        n= nums.size();
        seg.resize(4*n +1, 0);
        lazy.resize(4*n +1, 0);
        build(0, 0, n-1, nums);
    }

    void build(int i, int low, int high, vector<int> &nums){
        if (low== high) {
            seg[i]= nums[low];
            return;
        }
        int mid= low+ (high-low)/2;
        build(2*i +1, low, mid, nums);
        build(2*i +2, mid+1, high, nums);
        seg[i]= seg[2*i +1]+ seg[2*i +2];
    }

    // perform pending updates on the current node
    void lazyUpdate(int index, int low, int high){
        if (lazy[index] != 0){
            seg[index] += (high-low+1) * lazy[index];
            if (low != high){
                lazy[2*index +1] += lazy[index];
                lazy[2*index +2] += lazy[index];
            }
            lazy[index]= 0;
        }
    }
    
    // add val to all elements in the range [left, right]
    void rangeUpdate(int left, int right, ll val, int i=0, int low= 0, int high= -1) {
        if (high == -1) return rangeUpdate(left, right, val, i, low, n-1);
        
        lazyUpdate(i, low, high);

        if (left > high || right < low || low > high) return;

        if (left <= low && right >= high){
            lazy[i]= val;
            lazyUpdate(i, low, high);
            return;
        }

        int mid= low+ (high-low)/2;
        rangeUpdate(left, right, val, 2*i +1, low, mid);
        rangeUpdate(left, right, val, 2*i +2, mid+1, high);
        seg[i]= seg[2*i +1] + seg[2*i +2];
    }
    
    // get sum of elements in the range [left, right]
    ll get(int left, int right, int i=0, int low= 0, int high= -1) {
        if (high == -1) return get(left, right, i, low, n-1);
        
        lazyUpdate(i, low, high);

        if (left > high || right < low || low > high) return 0;
        if (left <= low && right >= high) return seg[i];
        int mid= low + (high-low)/2;
        return (get(left, right, 2*i +1, low, mid) + get(left, right, 2*i +2, mid+1, high));
    }
};