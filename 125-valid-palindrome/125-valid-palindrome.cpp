class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(auto c:s){
            if(c>='a' && c<='z'){
                s1+=c;
            }else if(c>='A' && c<='Z'){
                s1+=(c+32);
            }else if(c>='0' && c<='9'){
                s1+=c;
            }
        }
        cout<<s1;
        int l=0, r=s1.size()-1;
        if(s1.size()==1) return true;
        while(l<=r){
            if(s1[l]!=s1[r]) return false;
            //cout<<s[l]<<' '<<s[r]<<endl;
            l++; r--;
        }
       return true; 
    }
};