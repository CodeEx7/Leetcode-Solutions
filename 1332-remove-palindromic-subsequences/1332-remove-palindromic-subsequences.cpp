class Solution {
public:
    bool palindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
               return false; 
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(palindrome(s)==true)
            return 1;
        else
            return 2;
    }
};