class NumArray {
public:
    vector<int>nums;
    vector<int>sums;
    int n;
    int buildst(int l, int r, int i){
        if(l>r) return 0;
        if(l==r){
            sums[i] = nums[l];
            return sums[i];
        }
        int m = l+(r-l)/2;
        sums[i] = buildst(l,m,2*i+1) + buildst(m+1,r,2*i+2);
        return sums[i];
    }
    
    NumArray(vector<int>& nums2) {
        n = nums2.size();
        nums = nums2;
        sums.resize(4*n);
        buildst(0,n-1,0);
    }
    
    int sumst(int i, int j, int l, int r, int idx){
        if(j<l or i>r) return 0;
        if(i<=l and j>=r) return sums[idx];
        int m = l+(r-l)/2;
        return sumst(i,j,l,m,2*idx+1)+sumst(i,j,m+1,r,2*idx+2);
        
    }
    
    int sumRange(int left, int right) {
        return sumst(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */