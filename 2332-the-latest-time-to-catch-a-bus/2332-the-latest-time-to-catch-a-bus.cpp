class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int bus = 0;
        int last_passenger = -1;
        int passenger = 0;
        int pass_in_this_bus;
        while(bus<buses.size()){
            pass_in_this_bus = 0;
            while(pass_in_this_bus<capacity && passenger<passengers.size() && passengers[passenger]<=buses[bus]){
                last_passenger = passenger;
                passenger++;
                pass_in_this_bus++;
            }
            bus++;
        }
        
        set<int>s;
        for(auto pass:passengers){
            s.insert(pass);
        }
        
        int ans;
        if(pass_in_this_bus!=capacity){
            ans = buses[buses.size()-1];
            while(s.find(ans)!=s.end()){
                ans--;
            }
            return ans;
        }
        //cout<<last_passenger<<endl;
        ans = passengers[last_passenger]-1;
        while(s.find(ans)!=s.end()){
            ans--;
        }
        return ans;
    }
};