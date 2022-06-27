class Solution {
public:
    int minPartitions(string n) {
        int ans = 1;
        int m = n.length();
        for(int i=0;i<m;i++){
            if(n[i]-'0'>ans)
                ans = n[i]-'0';
        }
        return ans;
    }
};