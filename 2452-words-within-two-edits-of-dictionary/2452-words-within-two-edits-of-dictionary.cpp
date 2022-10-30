class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto q:queries){
            int n = q.size();
            for(auto d:dictionary){
                int c = 0;
                for(int i=0;i<n;i++){
                    if(q[i] != d[i]) c++;
                }
                if(c<3){
                    ans.push_back(q);
                    break;
                }
            }
            
        }
        return ans;
    }
};