class NumArray {
public:
    vector<int>pre_sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        pre_sum.push_back(nums[0]);
        for(int i=1;i<n;i++){
            sum+= nums[i];
            pre_sum.push_back(sum);
        }
        return;
    }
    
    int sumRange(int left, int right) {
        if(left==0) return pre_sum[right];
        return pre_sum[right]-pre_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */