class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        int n = r.size(), m = c.size();
        vector<int>adj1[k+1], adj2[k+1];
        vector<int>ind1(k+1,0),ind2(k+1,0);
        for(auto rr:r){
            adj1[rr[0]].push_back(rr[1]);
            ind1[rr[1]]++;
        }
        for(auto cc:c){
            adj2[cc[0]].push_back(cc[1]);
            ind2[cc[1]]++;
        }
        
        vector<int>iv(k+1,0);
        vector<bool>visit1(k+1,false);
        queue<int>q1;
        for(int i=1;i<=k;i++){
            if(ind1[i]==0){
                q1.push(i);
                visit1[i] = true;
            }
        }
        int count1 = 0;
        int d1 = 0;
        while(!q1.empty()){
            int sz = q1.size();
            count1+=sz;
            while(sz--){
                int f = q1.front(); q1.pop();
                iv[f] = d1;
                for(auto next:adj1[f]){
                    ind1[next]--;
                    if(ind1[next]==0 and visit1[next]==false){
                        q1.push(next);
                        visit1[next] = true;
                    }
                }
                d1++;
            } 
        }
        if(count1<k) return {};
        vector<int>jv(k+1,0);
        vector<bool>visit2(k+1,false);
        queue<int>q2;
        for(int i=1;i<=k;i++){
            if(ind2[i]==0){
                q2.push(i);
                visit2[i] = true;
            }
        }
        int count2 = 0;
        int d2 = 0;
        while(q2.size()){
            int sz = q2.size();
            count2+=sz;
            while(sz--){
                int f = q2.front(); q2.pop();
                jv[f] = d2;
                for(auto next:adj2[f]){
                    ind2[next]--;
                    if(ind2[next]==0 and visit2[next]==false){
                        q2.push(next);
                        visit2[next] = true;
                    }
                }
                d2++;
            }
        }
        if(count2<k) return {};
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[iv[i]][jv[i]] = i;
        }
        return ans;
    }
};