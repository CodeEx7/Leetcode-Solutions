class Solution {
public:
    string reverseWords(string s) {
        string res="", temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                reverse(temp.begin(), temp.end());
                res+=temp;
                res+=" ";
                temp.clear();
            }
        }
        reverse(temp.begin(), temp.end());
        res+=temp;        
       return res; 
    }
};