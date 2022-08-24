class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
       int val=ceil(log(n)/log(3));
            return (n==pow(3,val));
    }
};