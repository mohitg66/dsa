// Segment Tree | Maximum Sum Subarray for whole array with Point Update
class SegmentTree {
public:
    vector<vector<ll>> seg;
    int n;

    SegmentTree(vector<int>& nums) {
        n= nums.size();
        seg.resize(4*n +1, vector<ll>(4, 0));
        build(0, 0, n-1, nums);
    }

    #define ALL 3   // sum of all elements in the range
    #define R 2     // maximum sum subarray ending at right
    #define L 1     // maximum sum subarray starting from left
    #define M 0     // maximum sum subarray

    // update the values of seg[i] based on the values of seg[2*i +1] and seg[2*i +2]
    void updateSeg(int i){
        seg[i][ALL] = seg[2*i +1][ALL] + seg[2*i +2][ALL];
        seg[i][R] = max(seg[2*i +2][R], seg[2*i +2][ALL] + seg[2*i +1][R]);
        seg[i][L] = max(seg[2*i +1][L], seg[2*i +1][ALL] + seg[2*i +2][L]);
        seg[i][M] = max(seg[2*i +1][R] + seg[2*i +2][L], max(seg[2*i +1][M], seg[2*i +2][M]));
    }

    // build the segment tree
    void build(int i, int low, int high, vector<int> &nums){
        if (low== high) {
            seg[i]= {max(0, nums[low]), max(0, nums[low]), max(0, nums[low]), nums[low]};
            return;
        }
        int mid= low+ (high-low)/2;
        build(2*i +1, low, mid, nums);
        build(2*i +2, mid+1, high, nums);

        updateSeg(i);
    }

    // update the value at index to val
    void update(int index, ll val, int i=0, int low= 0, int high= -1) {
        if (high == -1) return update(index, val, i, low, n-1);
        if (low==high) {
            seg[i]= {max(0LL, val), max(0LL, val), max(0LL, val), val};
            return;
        }
        int mid= low+ (high-low)/2;
        if (index <= mid) 
            update(index, val, 2*i +1, low, mid);
        else
            update(index, val, 2*i +2, mid+1, high);

        updateSeg(i);
    }

    // the maximum sum subarray in the range [0, n-1] is stored at seg[0][0]
};