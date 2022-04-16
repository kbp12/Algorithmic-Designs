class NumArray {
public:
    vector<int>tree;
    int n;
    int constructST(vector<int>& nums, int l, int r, int idx){
        if(l==r){
            tree[idx] = nums[l];
            return tree[idx];
        }
        int m = (l+r)/2;
        tree[idx] = constructST(nums,l,m,2*idx+1)+
            constructST(nums,m+1,r,2*idx+2);
        return tree[idx];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        constructST(nums,0,n-1,0);
        return;
    }
    int getSum(int l, int r, int left, int right, int idx){
        if(l>right || r<left){
            return 0;
        }
        if(l<=left && r>=right) return tree[idx];
        int m = (left+right)/2;
        return getSum(l,r,left,m,2*idx+1)+getSum(l,r,m+1,right,2*idx+2);
    }
    
    int sumRange(int left, int right) {
        return getSum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */