class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = 0, lastEnd = -1, lastLen = 0;
        map<int, int> validEnds;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                if(!st.empty()) {
                    int lenTemp = i - st.top() + 1;
                    if(validEnds.find(st.top() - 1) != validEnds.end())
                        lenTemp += validEnds[st.top() - 1];
                    len = max(len, lenTemp);
                    validEnds.insert({i, lenTemp});
                    st.pop();
                }
            }
        }
        return len;
    }
};