class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>uset;
        for(auto b:bank) uset.insert(b);
        int ans = 1;
        queue<string>q;
        q.push(start);
        vector<char>v = {'A' , 'C' , 'G' , 'T'};
        while(q.size()){
            int n = q.size();
            while(n--){
                string s = q.front(); q.pop();
                for(int i=0;i<8;i++){
                    char ch = s[i];
                    for(int j=0;j<4;j++){
                        if(ch != v[j]){
                            s[i] = v[j];
                            if(uset.find(s) != uset.end()){
                                if(s == end) return ans;
                                q.push(s);
                                uset.erase(s);
                            }
                        }
                    }
                    s[i] = ch;
                }
            }
            ans++;
        }
        return -1;
    }
};