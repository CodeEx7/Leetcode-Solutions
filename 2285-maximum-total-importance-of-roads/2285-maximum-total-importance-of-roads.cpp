class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<long long>v(n,0);
      for(auto it:roads){
        v[it[0]]++;
        v[it[1]]++;
      }
      long long ans=0;
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
        ans+=v[i]*(i+1);
      }
      return ans;
    }
};