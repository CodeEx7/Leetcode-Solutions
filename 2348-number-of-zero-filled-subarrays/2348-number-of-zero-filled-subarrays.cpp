#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        ll n=nums.size();
        ll cnt=0;
        for(int i:nums){
            if(i==0){
                cnt++;
            }else{
                ans+=(cnt*(cnt+1)/2);
                cnt=0;
            }
        }
        if(cnt!=0){
            ans+=(cnt*(cnt+1)/2);
            //cnt=0;
        }
        return ans;
    }
};