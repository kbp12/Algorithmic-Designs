class FoodRatings {
public:
    map<string,string> link;
    map<string,int> rat;
    map<string,set<pair<int,string>>> cus;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n = f.size();
        for(int i=0;i<n;i++){
            link[f[i]] = c[i];
            rat[f[i]] = r[i];
        }
        
        for(int i=0;i<n;i++){
            cus[c[i]].insert({r[i],f[i]});
        }
        return;
    }
    
    void changeRating(string food, int nr) {
        
        cus[link[food]].erase(cus[link[food]].find({rat[food],food}));
        cus[link[food]].insert({nr,food});
        rat[food]=nr;
        return ;
    }
    
    string highestRated(string cuisine) {
        pair<int,string> pa =  *(cus[cuisine].rbegin());
        string res = pa.second;
        for(auto itr=(cus[cuisine].rbegin());itr!=(cus[cuisine].rend());itr++){
            if(itr->first != pa.first) 
                return res;
            else 
                res = itr->second;
        }
        return res;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */