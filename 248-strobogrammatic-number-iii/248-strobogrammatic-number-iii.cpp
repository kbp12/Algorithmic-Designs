class Solution {
public:
    
    bool compare(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        if (n != m)
            return n <= m;

        for (int i = 0; i < n; i++) {
            if (s1[i] < s2[i]) return true;
            else if (s1[i] > s2[i]) return false;
        }

        return true;
    }
    
    void strobogrammaticInRange(vector<pair<char,char>> &nums, string &low, string &high, string &t, int &cnt){
        if(!compare(t,high)){
            return;
        }
        if(compare(low,t) and compare(t,high)){
            if(t.length()==1 or (t.length()>1 and t[0]!='0')){
                cnt++;
            }
        }
        
        string x = '#' + t + '#';
        int size=x.size();
        for(auto p: nums){
            x[0] = p.first;
            x[size-1]=p.second;
            strobogrammaticInRange(nums, low, high, x, cnt);
        }
        return;
    }
    
    int strobogrammaticInRange(string low, string high) {
        if (!compare(low, high)) return 0;
        
        vector<pair<char, char>> nums;
        nums.push_back({'0','0'});
        nums.push_back({'1','1'});
        nums.push_back({'6','9'});
        nums.push_back({'8','8'});
        nums.push_back({'9','6'});
        
        int cnt = 0;
        string s="";
        strobogrammaticInRange(nums, low, high, s, cnt);
        s="0";
        strobogrammaticInRange(nums, low, high, s, cnt);
        s="1";
        strobogrammaticInRange(nums, low, high, s, cnt);
        s="8";
        strobogrammaticInRange(nums, low, high, s, cnt);
        return cnt;
    }
};