class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int j = str.length();
        int i=0;
        stack<int>stck;
        while(i<j){
            if(str[i]!=')' && str[i]!='('){
                
            }
            else if(str[i]=='('){
                stck.push(i);
            }else{
               if(stck.size() && str[stck.top()]=='(')
                   stck.pop();
                else
                    stck.push(i);
            }
            i++;
        }
        string ans = "";
        for(int i=j-1;i>=0;i--){
            if(stck.size() && stck.top()==i){
                stck.pop();
            }else{
                ans.push_back(str[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};