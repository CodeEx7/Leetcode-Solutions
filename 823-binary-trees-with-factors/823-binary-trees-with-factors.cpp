class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long int mod=pow(10,9)+7;
        unordered_map<int,long long int> mapp;
        for(auto num:arr){
            mapp[num]=1;
        }
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            long long int cnt=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    if(mapp.find(arr[i]/arr[j])!=mapp.end()){
                        cnt+=(mapp[arr[j]]*mapp[arr[i]/arr[j]]);
                    }
                }
            }
            mapp[arr[i]]+=cnt;
        }
        long long int res=0;
        for(auto it:mapp){
            res+=it.second;
        }
        return res%mod;
    }
};