class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       sort(arr.begin(), arr.end(), [x](const auto a, const auto b){
            if(abs(a-x)==abs(b-x)){
                return a<b;
            }
           return (abs(a-x)<abs(b-x));
        });
        
        vector<int> res;
        for(int i=0;i<k;i++){
            res.emplace_back(arr[i]);
        }
        
        sort(res.begin(), res.end());          
        return res; 
    }
};