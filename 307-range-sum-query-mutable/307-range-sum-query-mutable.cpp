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
    
    void updatest(int l, int r, int diff, int i, int idx){
        if(idx<l || idx>r) return;
        sums[i]+=diff;
        if(l==r) return;
        int m = l+(r-l)/2;
        updatest(l,m,diff,2*i+1,idx);
        updatest(m+1,r,diff,2*i+2,idx);
        return;
    }
    
    int sumst(int start, int end, int l, int r, int i){
        if(l>end || r<start) return 0;
        if(l<=start && end<=r) return sums[i];
        int mid = start+(end-start)/2;
        return sumst(start,mid,l,r,2*i+1)+sumst(mid+1,end,l,r,2*i+2);
    }
    
    NumArray(vector<int>& nums2){
        n = nums2.size();
        nums = nums2;
        sums.resize(4*n);
        buildst(0,n-1,0);
    }
    
    void update(int index, int val){
        int diff = val-nums[index];
        nums[index] = val;
        updatest(0,n-1,diff,0,index);
        return;
    }
    
    int sumRange(int l, int r){
        return sumst(0,n-1,l,r,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */