class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({{1}});
        if(n==1) return res;
        res.push_back({{1,1}});
        if(n==2) return res;
        
        for(int i=2;i<n;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<temp.size()-1;j++){
                temp[j]=res.back()[j]+res.back()[j-1];
            }
            res.push_back(temp);
        }
        return res;
    }
};