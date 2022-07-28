class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n-1;i++){
            int ma = nums[i], mi = nums[i];
            for(int j=i+1;j<n;j++){
                ma=max(ma, nums[j]);
                mi=min(mi, nums[j]);
                res+=ma-mi;
            }
        }
        return res;
    }
};