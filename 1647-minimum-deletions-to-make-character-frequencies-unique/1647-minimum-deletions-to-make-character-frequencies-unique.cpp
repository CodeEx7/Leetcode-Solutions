class Solution {
public:
    int minDeletions(string s) {
       vector<int> freq(26, 0);
        for(auto ch:s){ //O(n)
            freq[ch-'a']++;
        }
        
        int res=0;
        unordered_set<int> st;
        st.insert(freq[0]);
        for(int i=1;i<26;i++){
            if(st.find(freq[i])!=st.end()){
                int temp=freq[i];
                while(temp>0){
                    if(st.find(temp)!=st.end()){
                        res++;
                        temp--;
                    }else{
                        st.insert(temp);
                        break;
                    }
                }
            }else{
                st.insert(freq[i]);
            }
        }
        return res;
    }
};