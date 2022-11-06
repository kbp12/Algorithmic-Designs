class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>pqfront,pqback;
        int n = costs.size();
        int l = 0, r = n-1;
        for(int i=0;i<candidates;i++){
            pqfront.push(costs[i]);
        }
        l = candidates;
        r = max(candidates , n-candidates) -1;
        for(int i=r+1;i<n;i++){
            pqback.push(costs[i]);
        }
        long long ans = 0;
        while(k--){
            int a=INT_MAX,b=INT_MAX;
            if(pqfront.size()){
                a = pqfront.top(); pqfront.pop();
            }
            if(pqback.size()){
                b = pqback.top(); pqback.pop();
            }
            if(a<=b){
                ans+=a;
                pqback.push(b);
                if(l<=r){
                    pqfront.push(costs[l]);
                    l++;
                }
            }else{
                ans+=b;
                pqfront.push(a);
                if(l<=r){
                    pqback.push(costs[r]);
                    r--;
                }
            }
        }
        return ans;
    }
};