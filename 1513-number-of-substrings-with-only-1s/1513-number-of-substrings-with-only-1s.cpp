#define ll long long
class Solution {
public:
    int numSub(string s) {
        ll ans=0;
        ll cnt=0;
        for( auto ch:s){
            if(ch=='1'){
                cnt++;
            }else{
                ans+=(cnt*(cnt+1)/2);
                ans=ans%1000000007;
                cnt=0;
            }
        }
        if(cnt!=0){
            ans+=(cnt*(cnt+1)/2);
            ans=ans%1000000007;
        }
        return ans;
    }
};