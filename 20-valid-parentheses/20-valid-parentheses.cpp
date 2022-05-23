class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
      for(auto c:s){
          if(c=='(' || c=='[' || c=='{'){
              st.push(c);
          }
          else{
              if(st.size() == 0) return false; 
              char nc=st.top();
              st.pop();
              if(nc=='(' && c!=')') return false;
              if(nc=='{' && c!='}') return false;
              if(nc=='[' && c!=']') return false;
          }
      }
        return st.empty();
    }
};