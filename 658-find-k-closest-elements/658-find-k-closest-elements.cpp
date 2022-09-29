class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       sort(arr.begin(), arr.end(), [x](const auto a, const auto b){
            if(abs(a-x)==abs(b-x)){
                return a<b;
            }
           return (abs(a-x)<abs(b-x));
        });
        
        arr.resize(k);
        
        sort(arr.begin(), arr.end());          
        return arr; 
    }
};