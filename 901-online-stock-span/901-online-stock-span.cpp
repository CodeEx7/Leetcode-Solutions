class StockSpanner {
    stack<pair<int,int>> s;
    int day;
public:
    StockSpanner() { 
        day = 0;
        s.push({INT_MAX,0});
    }
    
    int next(int price) {
        day++;
        while(s.top().first <= price){ s.pop(); }
        int span = day - s.top().second;
        s.push({price, day});
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = oj->next(price);
 */