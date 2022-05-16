class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int pairity = 0;
        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==-1){
                pairity--;
            }
            if(nums[i]==pairity%2){
                nums[i] = -1;
                if(i+k>n) return -1;
                pairity++;
                ans++;
            }
        }
        return ans;
    }
};