class MyHashSet {
public:
    MyHashSet() {
        
    }
    vector<int>v;
    void add(int key) {
        if(find(v.begin(),v.end(),key)==v.end())v.push_back(key);
        return;
    }
    
    void remove(int key) {
        if(find(v.begin(),v.end(),key)!=v.end())
            v.erase(find(v.begin(),v.end(),key));
        return;
    }
    
    bool contains(int key) {
        for(int i=0;i<v.size();i++) if(v[i]==key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */