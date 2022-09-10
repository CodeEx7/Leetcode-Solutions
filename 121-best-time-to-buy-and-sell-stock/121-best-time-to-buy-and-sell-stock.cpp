class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_stock=INT_MAX;
        int res=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>min_stock){
                res=max(res,prices[i]-min_stock);
            }else{
                min_stock=min(min_stock,prices[i]);
            }
        }
        return res;
    }
};