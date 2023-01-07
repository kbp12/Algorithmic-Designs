class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int it = 1;
        for(auto t:target){
            while(it!=t){
                ans.push_back("Push");
                ans.push_back("Pop");
                it++;
            }
            ans.push_back("Push");
            it++;
        }
        return ans;
    }
};