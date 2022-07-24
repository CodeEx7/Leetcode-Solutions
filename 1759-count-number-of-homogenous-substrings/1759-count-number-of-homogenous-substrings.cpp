#define ll long long 
class Solution {
public:
    int countHomogenous(string s) {
        ll ans=0, cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                ans+=(cnt*(cnt+1)/2);
                ans=ans%1000000007;
                cnt=1;
            }
        }
        if(cnt!=0){
            ans+=(cnt*(cnt+1)/2);
            ans=ans%1000000007;
        }
        return ans;
    }
};