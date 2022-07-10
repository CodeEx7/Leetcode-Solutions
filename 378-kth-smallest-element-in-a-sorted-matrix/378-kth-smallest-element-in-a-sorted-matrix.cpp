class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(mat[i][j]);
                //if(pq.size()>k) pq.pop();
            }
        }
         for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};