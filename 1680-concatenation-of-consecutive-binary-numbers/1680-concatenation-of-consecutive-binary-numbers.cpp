class Solution {
public:
    int concatenatedBinary(int n) {
        int mod=1000000007;
        long long int res=0;
        for(int i=1;i<=n;i++){
            int d=log2(i)+1;
            res=(res<<d)+i;
            res=res%mod;
        }
        return res%mod;
    }
};