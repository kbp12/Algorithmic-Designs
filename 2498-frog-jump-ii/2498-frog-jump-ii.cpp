class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int val = INT_MIN;
        if(n<3) return stones[1] - stones[0];
        for(int i=2;i<n;i++){
            val = max(val , stones[i] - stones[i-2]);
        }
        return val;
    }
};