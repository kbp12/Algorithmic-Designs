class NumArray {
public:
    vector<int>arr;
    int n;
    vector<int>seg;
    int buildseg(int l, int r, int idx){
        if(l>r) return 0;
        if(l==r){
            seg[idx] = arr[l];
            return seg[idx];
        }
        int m = l+(r-l)/2;
        seg[idx] = buildseg(l,m,2*idx+1)+buildseg(m+1,r,2*idx+2);
        return seg[idx];
    }
    
    NumArray(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        seg.resize(4*n);
        buildseg(0,n-1,0);
        return;
    }
    
    void updateseg(int l, int r, int idx, int index, int diff){
        if(index<l or index>r) return;
        seg[idx]+=diff;
        if(l==r) return;
        int m = l+(r-l)/2;
        updateseg(l,m,2*idx+1,index,diff);
        updateseg(m+1,r,2*idx+2,index,diff);
        return;
    }
    void update(int index, int val) {
        int diff = val-arr[index];
        arr[index] = val;
        updateseg(0,n-1,0,index,diff);
    }
    
    int sumseg(int left, int right, int l, int r, int idx){
        if(right<l or left>r) return 0;
        if(left<=l and r<=right) return seg[idx];
        int m = l+(r-l)/2;
        return sumseg(left,right,l,m,2*idx+1)+sumseg(left,right,m+1,r,2*idx+2);
    }
    int sumRange(int left, int right) {
        return sumseg(left,right,0,n-1,0);  
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */