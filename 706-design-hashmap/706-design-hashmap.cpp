class MyHashMap {
public:
    MyHashMap() {
        
    }
    unordered_map<int,int>m;
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        return m[key];
    }
    
    void remove(int key) {
        if(m.find(key)!=m.end()){
            m.erase(m.find(key));
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */