class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int n = nums.size();
        vector<int> leftf(n,0) , rightf(n,0) , lefts(n,0) , rights(n,0);
        int l = 0 , r = 0;
        for(int i=0;i<f;i++){
            l+= nums[i];
            r+= nums[n-1-i];
        }
        leftf[f-1] = l;
        rightf[n-f] = r;
        for(int i=f;i<n;i++){
            l += (nums[i]-nums[i-f]);
            r += (nums[n-1-i]-nums[n-1+f-i]);
            leftf[i] = max(leftf[i-1],l);
            rightf[n-1-i] = max(rightf[n-i],r);
        }
        l=0, r=0;
        for(int i=0;i<s;i++){
            l+= nums[i];
            r+= nums[n-1-i];
        }
        lefts[s-1] = l;
        rights[n-s] = r;
        for(int i=s;i<n;i++){
            l += (nums[i]-nums[i-s]);
            r += (nums[n-1-i]-nums[n-1+s-i]);
            lefts[i] = max(lefts[i-1],l);
            rights[n-1-i] = max(rights[n-i],r);
        }
        int ans1 = 0, ans2 = 0;
        for(int i=f-1;i<(n-s);i++){
            ans1 = max(ans1, leftf[i]+rights[i+1]);
        }
        for(int i=s-1;i<(n-f);i++){
            ans2 = max(ans2, lefts[i]+rightf[i+1]);
        }
        return max(ans1,ans2);
    }
};