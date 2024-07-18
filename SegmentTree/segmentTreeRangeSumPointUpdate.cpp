// Segment Tree | Range Query and Point Update
class SegmentTree {
public:
    vector<ll> seg;
    int n;

    SegmentTree(vector<int>& nums) {
        n= nums.size();
        seg.resize(4*n +1, 0);
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
    
    // update the value at index to val
    void update(int index, ll val, int i=0, int low= 0, int high= -1) {
        if (high == -1) return update(index, val, i, low, n-1);
        if (low==high) {
            seg[i]= val;
            return;
        }
        int mid= low+ (high-low)/2;
        if (index <= mid) 
            update(index, val, 2*i +1, low, mid);
        else
            update(index, val, 2*i +2, mid+1, high);
        seg[i]= seg[2*i +1] + seg[2*i +2];
    }

    // get the sum of elements in the range [left, right]
    ll get(int left, int right, int i=0, int low= 0, int high= -1) {
        if (high == -1) return get(left, right, i, low, n-1);
        if (left > high || right < low || low > high) return 0;
        if (left <= low && right >= high) return seg[i];
        int mid= low + (high-low)/2;
        return (get(left, right, 2*i +1, low, mid) + get(left, right, 2*i +2, mid+1, high));
    }
};