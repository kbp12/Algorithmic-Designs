class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>answer(n,0);
        for(int i=0;i<bookings.size();i++){
            int a = bookings[i][0], b = bookings[i][1], c = bookings[i][2];
            answer[a-1]+= c;
            if(b<n){
                answer[b] -= c;
            }
        }
        for(int i=1;i<n;i++) answer[i] += answer[i-1];
        return answer;
    }
};