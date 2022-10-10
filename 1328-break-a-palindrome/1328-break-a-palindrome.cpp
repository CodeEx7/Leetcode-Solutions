class Solution {
public:
    string breakPalindrome(string pdr) {
        if(pdr.size()<2) return "";
        
        for(int i=0;i<pdr.size()/2;i++){
            if(pdr[i]!='a'){
                pdr[i]='a';
                return pdr;
            }
        }
        
        pdr[pdr.size()-1]='b';
        
        return pdr;
    }
};