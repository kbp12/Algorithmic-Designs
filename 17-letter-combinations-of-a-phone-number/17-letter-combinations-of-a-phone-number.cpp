class Solution {
public:
    vector<string>ans;
    string temp;
    void dfs(int n,int i, string digits){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        
        
        if(digits[i]=='2'){
            temp[i] = 'a';
            dfs(n,i+1,digits);
            temp[i] = 'b';
            dfs(n,i+1,digits);
            temp[i] = 'c';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='3'){
            temp[i] = 'd';
            dfs(n,i+1,digits);
            temp[i] = 'e';
            dfs(n,i+1,digits);
            temp[i] = 'f';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='4'){
            temp[i] = 'g';
            dfs(n,i+1,digits);
            temp[i] = 'h';
            dfs(n,i+1,digits);
            temp[i] = 'i';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='5'){
            temp[i] = 'j';
            dfs(n,i+1,digits);
            temp[i] = 'k';
            dfs(n,i+1,digits);
            temp[i] = 'l';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='6'){
            temp[i] = 'm';
            dfs(n,i+1,digits);
            temp[i] = 'n';
            dfs(n,i+1,digits);
            temp[i] = 'o';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='7'){
            temp[i] = 'p';
            dfs(n,i+1,digits);
            temp[i] = 'q';
            dfs(n,i+1,digits);
            temp[i] = 'r';
            dfs(n,i+1,digits);
            temp[i] = 's';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='8'){
            temp[i] = 't';
            dfs(n,i+1,digits);
            temp[i] = 'u';
            dfs(n,i+1,digits);
            temp[i] = 'v';
            dfs(n,i+1,digits);
            return;
        }
        if(digits[i]=='9'){
            temp[i] = 'w';
            dfs(n,i+1,digits);
            temp[i] = 'x';
            dfs(n,i+1,digits);
            temp[i] = 'y';
            dfs(n,i+1,digits);
            temp[i] = 'z';
            dfs(n,i+1,digits);
            return;
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if(n==0) return ans;
        temp = digits;
        dfs(n,0,digits);
        return ans;
    }
};