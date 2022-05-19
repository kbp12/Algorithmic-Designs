class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans="" ;
        int i=0;
        while(i<n){
            while(ans.size() && k && ans[ans.size()-1]>num[i]){
                ans.pop_back();
                k--;
            }
            if(ans.size()==0 && num[i]=='0'){i++; continue;}
            ans.push_back(num[i]);
            i++;
        }
        while(k && ans.size()){ans.pop_back(); k--;}
        if(ans.size()==0) return "0";
        return ans;
    }
};