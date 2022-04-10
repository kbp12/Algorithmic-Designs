class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){ s.pop();
            }else if(ops[i]=="+"){ int a = s.top(); s.pop(); 
                int b=s.top(); 
                s.push(a); s.push(a+b);
            }else if(ops[i]=="D"){ s.push(s.top()*2);
            }else{ s.push(stoi(ops[i])); }
        }
        int ans=0;
        while(s.size()){ ans+= s.top(); s.pop();}
        return ans;
    }
};