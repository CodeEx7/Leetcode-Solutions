class MyCalendarThree {
public:
    map<int,int> mapp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mapp[start]++;
        mapp[end]--;
        
        int res=0, count=0;
        for(auto it:mapp){
            count+=it.second;
            
            res=max(res,count);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */