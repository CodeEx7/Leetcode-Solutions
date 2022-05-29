class Solution {
public:
    bool check(unordered_set<char> &st, string &s2){   
        for(auto c:s2){
            if(st.find(c)!=st.end())
                return false;
        }
        return true;
    }
    //main working function
    int maxProduct(vector<string>& word) {
        int maxi=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            unordered_set<char> st;
              for(auto c:word[i]){
                st.insert(c);
              }
            for(int j=0;j<n;j++){
                if(i!=j && check(st, word[j])){;
                    int temp=(word[i].size()*word[j].size());
                    maxi=max(maxi, temp);
                }
            }
        }
        return maxi;
    }
};