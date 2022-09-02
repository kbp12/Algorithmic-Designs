class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>ans;
        int prev = lower;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==prev){
                prev++;
            }else{
                string a = to_string(prev);
                int temp = nums[i]-1;
                if(temp==prev){
                    ans.push_back(a);
                }else{
                    string b = to_string(temp);
                    ans.push_back(a+"->"+b);
                }
                prev = nums[i]+1;
            }
        }
        if(prev<=upper){
            string a = to_string(prev);
            if(prev==upper){
                ans.push_back(a);
            }else{
                string b = to_string(upper);
                ans.push_back(a+"->"+b);
            }
        }
        return ans;
    }
};