class Solution {
public:
    //--------------------------------------------
    static bool mycomp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    //---------------------------------------------
    int ceilIdx(vector<int> &arr, int target){
        int left=0, right=arr.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(arr[mid]>=target){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return right;
    }
    //---------------------------------------------
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), mycomp);
        
        //finding out LIS according to second value
        vector<int> tail;
        tail.emplace_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>tail.back()){
                tail.emplace_back(envelopes[i][1]);
            }else{
                int idx=ceilIdx(tail, envelopes[i][1]);
                tail[idx]=envelopes[i][1];
            }
        }
        return tail.size();
    }
};