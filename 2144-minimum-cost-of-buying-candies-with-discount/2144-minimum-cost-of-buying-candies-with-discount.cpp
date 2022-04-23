class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size()-1;
        sort(cost.begin(),cost.end());
        int ans = 0;
        while(n>2){
            ans+= cost[n]; n--;
            ans+= cost[n]; n--;
            n--;
        }
        if(n>=0){ans+= cost[n]; n--;}
        if(n>=0){ans+= cost[n];n--;}
        return ans;
    }
};