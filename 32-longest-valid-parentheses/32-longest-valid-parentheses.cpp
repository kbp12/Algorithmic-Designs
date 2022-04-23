class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int>stck;
        int j = str.length();
        int i=0;
        while(i<j){
            if(str[i]=='('){
                stck.push(i);
            }else{
                if(stck.size() && str[stck.top()]=='('){
                    stck.pop();
                }else{
                    stck.push(i);
                }
            }
            i++;
        }
        int ans = 0;
        while(stck.size()){
            ans = max(ans, j-stck.top()-1);
            j = stck.top();
            stck.pop();
        }
        if(j!=0){
            ans = max(ans,j);
        }
        return ans;
    }
};