class Solution {
public:
    bool checkIfPangram(string sentence) {
       unordered_set<char> st;
        
        for(auto ch:sentence){
            st.insert(ch);
        }
        
        return st.size()==26;
    }
};