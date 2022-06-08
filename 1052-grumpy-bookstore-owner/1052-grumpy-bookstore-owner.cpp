class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int total_customers = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                total_customers+= customers[i];
            }
        }
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                total_customers += customers[i];
            }
        }
        int maximum_customers = total_customers;
        for(int i=minutes;i<n;i++){
            if(grumpy[i]==1){
                total_customers+= customers[i];
            }
            if(grumpy[i-minutes]==1){
                total_customers-= customers[i-minutes];
            }
            maximum_customers = max(maximum_customers,total_customers);
        }
        return maximum_customers;
    }
};