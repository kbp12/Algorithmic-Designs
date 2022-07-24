class NumberContainers {
public:
    map<int,int>idnum;
    map<int,set<int>>m;
    NumberContainers() {
        
    }
    
    void change(int i, int n) {
        if(idnum.find(i)==idnum.end()){
            idnum[i] = n;
            m[n].insert(i);
        }else{
            int a = idnum[i];
            idnum[i] = n;
            m[a].erase(m[a].find(i));
            m[n].insert(i);
        }
        return;
    }
    
    int find(int n) {
        if(m[n].size()==0) return -1;
        return *m[n].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */