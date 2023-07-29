class NumArray {
    vector<int> seg;
    int n;
public:
    NumArray(vector<int>& nums) {
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
    
    void update(int index, int val, int i=0, int low= 0, int high= -1) {
        if (high == -1) return update(index, val, i, low, n-1);
        if (low==high) {
            seg[i]= val;
            return;
        }
        int mid= low+ (high-low)/2;
        if (index <= mid) 
            update(index, val, i*2 +1, low, mid);
        else
            update(index, val, i*2 +2, mid+1, high);
        seg[i]= seg[i*2 +1] + seg[i*2 +2];
    }
    
    int sumRange(int left, int right, int i=0, int low= 0, int high= -1) {
        if (high == -1) return sumRange(left, right, i, low, n-1);
        if (left <= low && right >= high) return seg[i];
        if (left > high || right < low) return 0;
        int mid= low + (high-low)/2;
        return (sumRange(left, right, i*2 +1, low, mid) + sumRange(left, right, i*2 +2, mid+1, high));
    }
};