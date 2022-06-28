class Solution {
public:
    int minDeletions(string s) {
       vector<int> freq(26, 0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        //sort(freq.begin(), freq.end());        
        
        // priority_queue<int> pq;
        // for(auto ch:freq){
        //     pq.push(ch);
        // }
        
        int res=0;
        unordered_set<int> st;
        st.insert(freq[0]);
        for(int i=1;i<freq.size();i++){
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