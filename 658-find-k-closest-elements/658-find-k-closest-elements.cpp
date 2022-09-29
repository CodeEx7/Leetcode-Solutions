class cmp {
    int param;
public:
    cmp(int x) : param(x) {}

    bool operator()(int a, int b) {
        if(abs(a-param)==abs(b-param)){
            return a<b;
        }
        return (abs(a-param)<abs(b-param));
    }
};
//main ----------------------------
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        
        sort(arr.begin(), arr.end(), cmp(x));
        
        for(int i=0;i<k;i++){
            res.emplace_back(arr[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};