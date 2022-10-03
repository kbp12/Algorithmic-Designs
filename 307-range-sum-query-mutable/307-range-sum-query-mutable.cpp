class NumArray {
public:
    vector<int> nums;
    int n; 
    vector<int>seg;
    int buildseg(int l, int r, int idx){
        if(l>r) return 0;
        if(l==r){
            seg[idx] = nums[l];
            return seg[idx];
        }
        int mid = l+(r-l)/2;
        seg[idx] = buildseg(l,mid,2*idx+1) + buildseg(mid+1,r,2*idx+2);
        return seg[idx];
    }
    
    NumArray(vector<int>& nums2) {
        nums = nums2;
        n = nums.size();
        seg.resize(4*n);
        buildseg(0,n-1,0);
    }
    
    void updateseg(int l, int r, int i, int idx, int diff){
        if(i<l or i>r) return;
        seg[idx]+=diff;
        if(l==r) return;
        int mid = l+(r-l)/2;
        updateseg(l,mid,i,2*idx+1,diff);
        updateseg(mid+1,r,i,2*idx+2,diff);
        return;
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateseg(0,n-1,index,0,diff);
        return;
    }
    
    int sumseg(int in, int out, int l, int r, int idx){
        if(in>r or out<l) return 0;
        if(in<=l and r<=out) return seg[idx];
        int mid = l + (r-l)/2;
        return sumseg(in, out, l,mid, 2*idx+1) + sumseg(in, out , mid+1, r, 2*idx+2);
    }
    
    int sumRange(int left, int right) {
        return sumseg(left,right,0,n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */