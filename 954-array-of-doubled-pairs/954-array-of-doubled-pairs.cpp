class Solution {
public:
    static bool compare(int a,int b){
        return abs(a)<abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        if(arr.size()%2!=0) return false;
        
        sort(arr.begin(), arr.end(), compare);
        
        unordered_map<int,int> mapp;
        for(auto ele:arr){
            mapp[ele]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(mapp[arr[i]]==0)  continue;
            if(mapp[arr[i]*2]==0) return false;
                mapp[arr[i]]--;
                mapp[2*arr[i]]--;
            
        }
        // for(auto it:mapp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // for(int i=0;i<arr.size();i++){
        //     if(mapp[arr[i]]!=0)
        //         return false;
        // }
        return true;
    }
};