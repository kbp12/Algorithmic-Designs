class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string>ans;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i]=='+' and s[i-1]=='+'){
                string temp = s;
                temp[i-1] = '-';
                temp[i] = '-';
                ans.push_back(temp);
            }
        }
        return ans;
    }
};