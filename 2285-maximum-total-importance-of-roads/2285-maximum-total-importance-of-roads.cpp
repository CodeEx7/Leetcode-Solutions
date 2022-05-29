class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<long long> deg(n,0);
      for(auto it:roads){
        deg[it[0]]++;
        deg[it[1]]++;
      }
      long long ans=0;
      sort(deg.begin(),deg.end());
        // for(auto it:deg){
        //     cout<<it<<" ";
        // }
      for(int i=0;i<n;i++){
        ans+=deg[i]*(i+1);
      }
      return ans;
    }
};