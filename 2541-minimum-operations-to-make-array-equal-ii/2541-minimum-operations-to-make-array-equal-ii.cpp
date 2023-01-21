class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long inc = 0, dec = 0;
        if(k == 0){
            if(nums1 == nums2) return 0;
            return -1;
        }
        for(int i=0;i<n;i++){
            if(nums1[i] == nums2[i]) continue;
            int t = abs(nums1[i] - nums2[i]);
            if(t%k) return -1;
            if(nums1[i] > nums2[i]){
                dec+= t/k; 
            }else{
                inc+=t/k;
            }
        }
        if(inc != dec) return -1;
        return inc;
    }
};