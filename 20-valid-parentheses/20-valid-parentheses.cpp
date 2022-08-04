class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        stack<char> st;
        for(auto ch:s){
            if(ch=='(' or ch=='{' or ch=='['){
                st.push(ch);
            }else{
                if(st.size()==0) return false;
                char curr=st.top();
                st.pop();
                if(curr=='(' and ch!=')') return false;
                if(curr=='{' and ch!='}') return false;
                if(curr=='[' and ch!=']') return false;
            }
        }
        return (st.size()==0);
    }
};