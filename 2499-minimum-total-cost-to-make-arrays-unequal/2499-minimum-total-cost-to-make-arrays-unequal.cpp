class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        vector<int> counts(n+1, 0);
        int dominantCnt = 0;
        int dominantNum = -1;
        int involvedCnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                counts[nums1[i]]++;
                if (counts[nums1[i]] > dominantCnt) {
                    dominantCnt = counts[nums1[i]];
                    dominantNum = nums1[i];
                }
                involvedCnt++;
            }
        }
        if (dominantCnt > involvedCnt / 2) {
            for (int i = 0; i < n; i++) {
                if ((nums1[i] != nums2[i]) && (nums1[i] != dominantNum) && (nums2[i] != dominantNum)){
                    counts[nums1[i]]++;
                    involvedCnt++;
                    ans += i;
                    if (dominantCnt <= involvedCnt / 2) {
                        return ans;
                    }
                }
            }
            return -1;
        }
        return ans;
    }
};