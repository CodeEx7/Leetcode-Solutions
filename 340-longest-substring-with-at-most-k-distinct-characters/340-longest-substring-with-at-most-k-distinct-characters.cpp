class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
         unordered_map<char, int> mapp;
        int left=0, right=0;
        int ans=0;
        while(right< s.size()){
            mapp[s[right]]=right;
            right++;
            
            if(mapp.size()>k){
                int minIdx=INT_MAX;
                for(auto it:mapp){
                    minIdx=min(minIdx, it.second);
                }
                mapp.erase(s[minIdx]);
                left=minIdx+1;
            }
            ans=max(ans, right-left);
        }
        return ans;
    }
};