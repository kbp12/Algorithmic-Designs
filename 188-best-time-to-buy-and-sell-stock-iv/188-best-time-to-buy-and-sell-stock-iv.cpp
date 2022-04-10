class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0) return 0;
        vector<int>buy(k,INT_MAX);
        vector<int>profit(k,0);
        for(int i=0;i<prices.size();i++){
            buy[0] = min( buy[0] , prices[i] );
            profit[0] = max( profit[0] , prices[i]-buy[0] );
            for(int j=1;j<k;j++){
                buy[j] = min( buy[j] , prices[i]-profit[j-1] );
                profit[j] = max( profit[j] , prices[i]-buy[j] );
            }
        }
        return profit[k-1];
    }
};