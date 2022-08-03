class MyCalendar {
public:
    vector<pair<int,int>> cal;
    MyCalendar() {
        cal.clear();
    }
    
    bool book(int start, int end) {
        for(auto it:cal){
            if(it.first<end && start<it.second){
                return false;
            }
        }
        cal.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */