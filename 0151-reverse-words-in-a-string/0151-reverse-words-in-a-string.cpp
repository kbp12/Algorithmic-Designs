class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans,word;
        int i=0;
        while(str >> word)
        {
            if(i==0)
            {
                ans = word;
                i++;
            }
            else
                ans = word + " " + ans;
        }
        return ans;
    }
};