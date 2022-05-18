class NumArray {
public:
    vector<int>sum;
    vector<int>nums;
    int n;
    
    int constructst(int s, int e, int idx){
        if(s==e){
            sum[idx] = nums[s];
            return nums[s];
        }
        int m = s+(e-s)/2;
        sum[idx] = constructst(s,m,idx*2+1)+constructst(m+1,e,idx*2+2);
        return sum[idx];
    }
    
    NumArray(vector<int>& nums2) {
        nums = nums2;
        n = nums.size();
        sum.resize(4*n);
        constructst(0,n-1,0);
    }
    
    void updatest(int s, int e, int idx, int d, int i){
        if(idx<s || idx>e) return;
        sum[i]+= d;
        if(s==e) return;
        int m = (s+e)/2;
        updatest(s,m,idx,d,2*i+1);
        updatest(m+1,e,idx,d,2*i+2);
        return;
    }
    
    void update(int idx, int val) {
        int d = val-nums[idx];
        nums[idx] = val;
        updatest(0,n-1,idx,d,0);
    }
    
    int getsum(int s, int e, int l, int r, int idx){
        if(l<=s && r>=e){
            return sum[idx];
        }
        if(l>e || r<s){
            return 0;
        }
        int m = s+(e-s)/2;
        return getsum(s,m,l,r,2*idx+1)+getsum(m+1,e,l,r,2*idx+2);
    }
    
    int sumRange(int left, int right) {
        return getsum(0,n-1,left,right,0);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */