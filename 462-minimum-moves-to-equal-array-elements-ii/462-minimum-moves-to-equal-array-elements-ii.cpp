class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==1) return 0;
        int mid;
        if(n%2==0){
            mid=nums[n/2];
        }else{
            mid=max(nums[n/2], nums[n/2-1]);
        }
        long long int res=0;
        for(int i=0;i<n;i++){
            res+=abs(nums[i]-mid);
        }
        return res;
    }
};