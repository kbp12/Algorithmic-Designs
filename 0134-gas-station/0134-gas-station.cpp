class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, total = 0, tank = 0;
        for(int i=0;i<n;i++){
            tank+=(gas[i] - cost[i]);
            if(tank<0){
                total += tank;
                start = i+1;
                tank = 0;
            }
        }
        if(total + tank < 0) return -1;
        return start;
    }
};