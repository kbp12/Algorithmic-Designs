class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    //<id,station name and checkin_time>
    unordered_map<int,pair<string,int>>check;
    unordered_map<string,pair<double,int>>ans;
    void checkIn(int id, string st_name, int t1) {
        check[id] = {st_name,t1};
    }
    
    void checkOut(int id, string st_name, int t2) {
        pair<string,int>p = check[id];
        double val = t2-p.second;
        string strs = p.first+"--"+st_name;
        if(ans.find(strs)==ans.end()){
            pair<double,int> res = {val,1};
            ans[strs] = res;
        }else{
            pair<double,int>prev = ans[strs];
            int n = prev.second;
            double value = prev.first*n;
            val = (val+value)/(n+1);
            pair<double,int> res = {val,n+1};
            ans[strs] = res;
        }
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string t = startStation+"--"+endStation;   
        return ans[t].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */