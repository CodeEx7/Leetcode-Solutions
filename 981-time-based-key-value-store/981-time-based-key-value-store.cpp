class TimeMap {
public:
    unordered_map<string,unordered_map<int, string>> mapp;
    TimeMap() {
       mapp.clear(); 
    }
    
    void set(string key, string value, int timestamp) {
        mapp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if (!mapp.count(key)) {
            return "";
        }
        for(int currTime=timestamp;currTime>=1;currTime--){
            if(mapp[key].count(currTime)){
                return mapp[key][currTime];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */