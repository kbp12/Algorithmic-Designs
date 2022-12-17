class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>v(n);
        bool z = true;
        for(int i=0;i<n;i++){
            if(nums[i]) z = false;    
            string s = to_string(nums[i]);
            v[i] = s;
        }
        if(z) return "0";
        sort(v.begin() , v.end() , [](string s1 , string s2){
            string s3 = s1+s2;
            string s4 = s2+s1;
            return s3>=s4;
        });
        string ans = "";
        for(int i=0;i<n;i++){ 
            ans+=v[i];
        }
        return ans;
    }
};