class Solution {
public:
    void generate(string s,int ind,vector<string> &ans,string &temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(s[ind]);
        generate(s,ind+1,ans,temp);
        temp.pop_back();
        
        if(s[ind]<='z' and s[ind]>='a'){
            temp.push_back(toupper(s[ind]));
            generate(s,ind+1,ans,temp);
            temp.pop_back();
        }else if(s[ind]<='Z' and s[ind]>='A'){
            temp.push_back(tolower(s[ind]));
            generate(s,ind+1,ans,temp);
            temp.pop_back();
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp="";
        generate(s,0,ans,temp);
        return ans;
    }
};