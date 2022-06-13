class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string substr="";
                while(st.top()!='['){
                    substr=st.top()+substr;
                    st.pop();
                }
                st.pop(); //to remove [ from stack
                string k="";
                while(st.empty()==false && isdigit(st.top())){
                    k=st.top()+k;
                    st.pop();
                }
                int temp=stoi(k);
                while(temp--){
                    for(int j=0;j<substr.size();j++){
                        st.push(substr[j]);
                    }
                }
            }
        }
        string res="";
        while(st.empty()==false){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};