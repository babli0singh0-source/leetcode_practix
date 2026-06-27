class LRUCache {
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>mpp;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mpp.count(key)==0)return -1;
        auto it=mpp[key];
        dll.splice(dll.begin(),dll,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            auto it=mpp[key];
            it->second=value;
            dll.splice(dll.begin(),dll,it);
            return;
        }
        if(mpp.size()==cap){
            mpp.erase(dll.back().first);
            dll.pop_back();
        }
        dll.push_front({key,value});
        mpp[key]=dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
